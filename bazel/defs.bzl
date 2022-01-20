# Copyright 2022 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

load("@emsdk//emscripten_toolchain:wasm_rules.bzl", "wasm_cc_binary")
load("@rules_cc//cc:defs.bzl", "cc_binary")

def proxy_wasm_cc_binary(
        name,
        additional_linker_inputs = [],
        copts = [],
        linkopts = [],
        tags = [],
        deps = [],
        **kwargs):
    cc_binary(
        name = "proxy_wasm_" + name.rstrip(".wasm"),
        additional_linker_inputs = additional_linker_inputs + [
            "@proxy_wasm_cpp_sdk//:proxy_wasm_intrinsics_js",
        ],
        copts = copts + [
            "-std=c++17",
            "-flto",
            "-O3",
        ],
        linkopts = linkopts + [
            "--no-entry",
            "--js-library=$(location @proxy_wasm_cpp_sdk//:proxy_wasm_intrinsics_js)",
            "-sSTANDALONE_WASM",
            "-sEXPORTED_FUNCTIONS=_malloc",
        ],
        tags = tags + [
            "manual",
        ],
        deps = deps + [
            "@proxy_wasm_cpp_sdk//:proxy_wasm_intrinsics",
        ],
        **kwargs
    )

    wasm_cc_binary(
        name = name,
        cc_target = ":proxy_wasm_" + name.rstrip(".wasm"),
        tags = tags,
    )
