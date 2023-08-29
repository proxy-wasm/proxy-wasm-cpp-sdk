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

def proxy_wasm_cpp_sdk_repositories():
    maybe(
        http_archive,
        name = "emsdk",
        sha256 = "05bad056df1286f920c675504787510434ae8b1b2d83746e0a9b0589429dbe55",
        # v3.1.44 with Bazel platforms fixes
        strip_prefix = "emsdk-9b0db91883452051aca8deddc932363aab29060b/bazel",
        url = "https://github.com/emscripten-core/emsdk/archive/9b0db91883452051aca8deddc932363aab29060b.tar.gz",
        patches = ["@proxy_wasm_cpp_sdk//bazel:emsdk.patch"],
        patch_args = ["-p2"],
    )

    maybe(
        http_archive,
        name = "com_google_protobuf",
        sha256 = "77ad26d3f65222fd96ccc18b055632b0bfedf295cb748b712a98ba1ac0b704b2",
        strip_prefix = "protobuf-3.17.3",
        url = "https://github.com/protocolbuffers/protobuf/releases/download/v3.17.3/protobuf-all-3.17.3.tar.gz",
    )
