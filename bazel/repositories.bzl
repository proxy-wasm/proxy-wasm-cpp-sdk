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

def proxy_wasm_cpp_host_repositories():
    maybe(
        http_archive,
        name = "emsdk",
        sha256 = "19851efd2616a66f9abd84f55f1d094e03252d87b1d78ae0f5d992121d1dd9cc",
        # v3.1.1 with Bazel fixes
        strip_prefix = "emsdk-7eecde8afcb89fbdff2597d6cce61a24ae2c34f3/bazel",
        url = "https://github.com/emscripten-core/emsdk/archive/7eecde8afcb89fbdff2597d6cce61a24ae2c34f3.tar.gz",
    )

    maybe(
        http_archive,
        name = "com_google_protobuf",
        sha256 = "77ad26d3f65222fd96ccc18b055632b0bfedf295cb748b712a98ba1ac0b704b2",
        strip_prefix = "protobuf-3.17.3",
        url = "https://github.com/protocolbuffers/protobuf/releases/download/v3.17.3/protobuf-all-3.17.3.tar.gz",
    )
