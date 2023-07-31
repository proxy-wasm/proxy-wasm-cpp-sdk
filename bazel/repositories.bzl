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
        sha256 = "52763f556d08ba0c0cde1840102e1e5fcf828b98924c4e77f629ad1d7d400933",
        # v3.1.44 with one Bazel platforms fix
        strip_prefix = "emsdk-ef2a8e929d5337755e9b1d1e1d4ad859dc694eee/bazel",
        url = "https://github.com/emscripten-core/emsdk/archive/ef2a8e929d5337755e9b1d1e1d4ad859dc694eee.tar.gz",
        patches = ["@proxy_wasm_cpp_sdk//bazel:emsdk.patch"],
        patch_args = ["-p2"],
    )

    maybe(
        http_archive,
        name = "com_google_protobuf",
        sha256 = "a700a49470d301f1190a487a923b5095bf60f08f4ae4cac9f5f7c36883d17971",
        strip_prefix = "protobuf-23.4",
        url = "https://github.com/protocolbuffers/protobuf/releases/download/v23.4/protobuf-23.4.tar.gz",
    )

    # Update protobuf dependency to fix unused function CodepointSkipBackwards.
    # https://github.com/protocolbuffers/utf8_range/commit/d863bc33e15cba6d873c878dcca9e6fe52b2f8cb
    # TODO(martijneken): Remove this when protobuf picks up the fix.
    maybe(
        http_archive,
        name = "utf8_range",
        sha256 = "568988b5f7261ca181468dba38849fabf59dd9200fb2ed4b2823da187ef84d8c",
        strip_prefix = "utf8_range-d863bc33e15cba6d873c878dcca9e6fe52b2f8cb",
        url = "https://github.com/protocolbuffers/utf8_range/archive/d863bc33e15cba6d873c878dcca9e6fe52b2f8cb.zip",
    )
