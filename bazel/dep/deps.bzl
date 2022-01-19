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

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

def wasm_dependencies():
    maybe(
        http_archive,
        name = "emscripten_toolchain",
        build_file = "@proxy_wasm_cpp_sdk//:emscripten-toolchain.BUILD",
        patch_cmds = [
            "./emsdk install 3.1.1",
            "./emsdk activate --embedded 3.1.1",
        ],
        strip_prefix = "emsdk-3.1.1",
        url = "https://github.com/emscripten-core/emsdk/archive/3.1.1.tar.gz",
        sha256 = "3a4893f0bb8203469e1197aa235fc49ed6f5dd2d490e9244a6899a8ad860f3e6",
    )

    maybe(
        http_archive,
        name = "com_google_protobuf",
        sha256 = "77ad26d3f65222fd96ccc18b055632b0bfedf295cb748b712a98ba1ac0b704b2",
        strip_prefix = "protobuf-3.17.3",
        url = "https://github.com/protocolbuffers/protobuf/releases/download/v3.17.3/protobuf-all-3.17.3.tar.gz",
    )
