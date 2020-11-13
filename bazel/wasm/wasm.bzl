load("@rules_cc//cc:defs.bzl", "cc_binary")

def _wasm_cc_transition_impl(settings, attr):
    return {
        "//command_line_option:cpu": "wasm32",
        "//command_line_option:crosstool_top": "@proxy_wasm_cpp_sdk//toolchain:emscripten",

        # Overriding copt/cxxopt/linkopt to prevent sanitizers/coverage options leak
        # into WASM build configuration
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

# WASM binary rule implementation.
# This copies the binary specified in binary attribute in WASM configuration to
# target configuration, so a binary in non-WASM configuration can depend on them.
wasm_cc_binary_rule = rule(
    implementation = wasm_binary_impl,
    attrs = _wasm_attrs(wasm_cc_transition),
)

def wasm_cc_binary(name, tags = [], **kwargs):
    wasm_name = "_wasm_" + name
    kwargs.setdefault("visibility", ["//visibility:public"])
    cc_binary(
        name = wasm_name,
        # Adding manual tag it won't be built in non-WASM (e.g. x86_64 config)
        # when an wildcard is specified, but it will be built in WASM configuration
        # when the wasm_binary below is built.
        tags = ["manual"],
        **kwargs
    )

    wasm_cc_binary_rule(
        name = name,
        binary = ":" + wasm_name,
        tags = tags + ["manual"],
    )
