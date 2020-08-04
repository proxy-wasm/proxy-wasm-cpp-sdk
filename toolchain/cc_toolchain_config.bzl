# Copyright 2019 Solo.io, Inc.
# Copyright 2020 Google LLC
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

load(
    "@bazel_tools//tools/cpp:cc_toolchain_config_lib.bzl",
    "feature",
    "flag_group",
    "flag_set",
    "tool_path",
)
load("@bazel_tools//tools/build_defs/cc:action_names.bzl", "ACTION_NAMES")

def _impl(ctx):
    tool_paths = [
        tool_path(
            name = "gcc",
            path = "emcc.sh",
        ),
        tool_path(
            name = "ld",
            path = "emcc.sh",
        ),
        tool_path(
            name = "ar",
            path = "emar.sh",
        ),
        tool_path(
            name = "cpp",
            path = "/bin/false",
        ),
        tool_path(
            name = "gcov",
            path = "/bin/false",
        ),
        tool_path(
            name = "nm",
            path = "/bin/false",
        ),
        tool_path(
            name = "objdump",
            path = "/bin/false",
        ),
        tool_path(
            name = "strip",
            path = "/bin/false",
        ),
    ]

    toolchain_include_directories_feature = feature(
        name = "toolchain_include_directories",
        enabled = True,
        flag_sets = [
            flag_set(
                actions = [
                    ACTION_NAMES.assemble,
                    ACTION_NAMES.preprocess_assemble,
                    ACTION_NAMES.linkstamp_compile,
                    ACTION_NAMES.c_compile,
                    ACTION_NAMES.cpp_compile,
                    ACTION_NAMES.cpp_header_parsing,
                    ACTION_NAMES.cpp_module_compile,
                    ACTION_NAMES.cpp_module_codegen,
                    ACTION_NAMES.lto_backend,
                    ACTION_NAMES.clif_match,
                ],
                flag_groups = [
                    flag_group(
                        flags = [
                            "-isystem",
                            "external/emscripten_toolchain/upstream/emscripten/system/include/libcxx",
                            "-isystem",
                            "external/emscripten_toolchain/upstream/emscripten/system/include/libc",
                        ],
                    ),
                ],
            ),
        ],
    )

    cxx17_feature = feature(
        name = "c++17",
        enabled = True,
        flag_sets = [
            flag_set(
                actions = [ACTION_NAMES.cpp_compile],
                flag_groups = [flag_group(flags = ["-std=c++17"])],
            ),
        ],
    )

    no_canonical_prefixes_feature = feature(
        name = "no-canonical-prefixes",
        enabled = True,
        flag_sets = [
            flag_set(
                actions = [
                    ACTION_NAMES.c_compile,
                    ACTION_NAMES.cpp_compile,
                    ACTION_NAMES.cpp_link_executable,
                    ACTION_NAMES.cpp_link_dynamic_library,
                    ACTION_NAMES.cpp_link_nodeps_dynamic_library,
                ],
                flag_groups = [
                    flag_group(
                        flags = [
                            "-no-canonical-prefixes",
                        ],
                    ),
                ],
            ),
        ],
    )

    opt_feature = feature(
        name = "opt",
        enabled = True,
        flag_sets = [
            flag_set(
                actions = [ACTION_NAMES.c_compile, ACTION_NAMES.cpp_compile],
                flag_groups = [
                    flag_group(
                        flags = ["-O3", "-ffunction-sections", "-fdata-sections", "--llvm-lto", "1", "-flto"],
                    ),
                ],
            ),
            flag_set(
                actions = [
                    ACTION_NAMES.cpp_link_dynamic_library,
                    ACTION_NAMES.cpp_link_nodeps_dynamic_library,
                    ACTION_NAMES.cpp_link_executable,
                ],
                flag_groups = [flag_group(flags = ["-O3", "-Wl,--gc-sections", "--llvm-lto", "1", "-flto"])],
            ),
        ],
    )

    return cc_common.create_cc_toolchain_config_info(
        ctx = ctx,
        toolchain_identifier = "wasm-toolchain",
        host_system_name = "i686-unknown-linux-gnu",
        target_system_name = "wasm32-unknown-emscripten",
        target_cpu = "wasm",
        target_libc = "unknown",
        compiler = "emscripten",
        abi_version = "unknown",
        abi_libc_version = "unknown",
        tool_paths = tool_paths,
        # we don't need to use features, as emcc already adds the directories.
        # we just need to include them here so that bazel doesn't complain on
        # "this rule is missing dependency declarations for the following files included".
        cxx_builtin_include_directories = [
            "external/emscripten_toolchain/upstream/emscripten/system/include/libcxx",
            "external/emscripten_toolchain/upstream/emscripten/system/include/libc",
        ],
        features = [cxx17_feature, no_canonical_prefixes_feature, opt_feature],
    )

cc_toolchain_config = rule(
    implementation = _impl,
    attrs = {},
    provides = [CcToolchainConfigInfo],
)
