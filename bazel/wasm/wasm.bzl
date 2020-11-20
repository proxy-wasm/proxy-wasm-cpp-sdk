#  Copyright 2016-2020 Envoy Project Authors
#  Copyright 2020 Google LLC
# 
#  Licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
# 
#       http://www.apache.org/licenses/LICENSE-2.0
# 
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.

load("@rules_cc//cc:defs.bzl", "cc_binary")

def _wasm_cc_transition_impl(settings, attr):
    return {
        "//command_line_option:cpu": "wasm32",
        "//command_line_option:crosstool_top": "@proxy_wasm_cpp_sdk//toolchain:emscripten",

        # Overriding copt/cxxopt/linkopt to prevent sanitizers/coverage options leak
        # into Wasm build configuration
        "//command_line_option:copt": [],
        "//command_line_option:cxxopt": [],
        "//command_line_option:linkopt": [],
        "//command_line_option:collect_code_coverage": "false",
        "//command_line_option:fission": "no",
    }

wasm_cc_transition = transition(
    implementation = _wasm_cc_transition_impl,
    inputs = [],
    outputs = [
        "//command_line_option:cpu",
        "//command_line_option:crosstool_top",
        "//command_line_option:copt",
        "//command_line_option:cxxopt",
        "//command_line_option:fission",
        "//command_line_option:linkopt",
        "//command_line_option:collect_code_coverage",
    ],
)

def wasm_binary_impl(ctx):
    out = ctx.actions.declare_file(ctx.label.name)
    ctx.actions.run(
        executable = "cp",
        arguments = [ctx.files.binary[0].path, out.path],
        outputs = [out],
        inputs = ctx.files.binary,
    )

    return [DefaultInfo(files = depset([out]), runfiles = ctx.runfiles([out]))]

def _wasm_attrs(transition):
    return {
        "binary": attr.label(mandatory = True, cfg = transition),
        "_whitelist_function_transition": attr.label(default = "@bazel_tools//tools/whitelists/function_transition_whitelist"),
    }

# Wasm binary rule implementation.
# This copies the binary specified in binary attribute in Wasm configuration to
# target configuration, so a binary in non-Wasm configuration can depend on them.
wasm_cc_binary_rule = rule(
    implementation = wasm_binary_impl,
    attrs = _wasm_attrs(wasm_cc_transition),
)

def wasm_cc_binary(name, tags = [], in_primary_repo = False, **kwargs):
    wasm_name = "_wasm_" + name
    kwargs.setdefault("additional_linker_inputs", ["@proxy_wasm_cpp_sdk//:jslib"])
    if in_primary_repo:
        js = "--js-library proxy_wasm_intrinsics.js"
    else:
        js = "--js-library external/proxy_wasm_cpp_sdk/proxy_wasm_intrinsics.js"
    kwargs.setdefault("linkopts", [js])
    kwargs.setdefault("visibility", ["//visibility:public"])
    cc_binary(
        name = wasm_name,
        # Adding manual tag it won't be built in non-Wasm (e.g. x86_64 config)
        # when an wildcard is specified, but it will be built in Wasm configuration
        # when the wasm_binary below is built.
        tags = ["manual"],
        **kwargs
    )

    wasm_cc_binary_rule(
        name = name,
        binary = ":" + wasm_name,
        tags = tags,
    )
