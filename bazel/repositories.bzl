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
        sha256 = "2d3292d508b4f5477f490b080b38a34aaefed43e85258a1de72cb8dde3f8f3af",
        strip_prefix = "emsdk-4.0.6/bazel",
        url = "https://github.com/emscripten-core/emsdk/archive/refs/tags/4.0.6.tar.gz",
    )

    # protobuf depends on rules_python py_repositories
    maybe(
        http_archive,
        name = "rules_python",
        sha256 = "9f9f3b300a9264e4c77999312ce663be5dee9a56e361a1f6fe7ec60e1beef9a3",
        strip_prefix = "rules_python-1.4.1",
        url = "https://github.com/bazelbuild/rules_python/releases/download/1.4.1/rules_python-1.4.1.tar.gz",
    )

    maybe(
        http_archive,
        name = "com_google_protobuf",
        sha256 = "008a11cc56f9b96679b4c285fd05f46d317d685be3ab524b2a310be0fbad987e",
        strip_prefix = "protobuf-29.3",
        url = "https://github.com/protocolbuffers/protobuf/releases/download/v29.3/protobuf-29.3.tar.gz",
    )

    maybe(
        http_archive,
        name = "com_google_absl",
        sha256 = "69909dd729932cbbabb9eeaff56179e8d124515f5d3ac906663d573d700b4c7d",
        strip_prefix = "abseil-cpp-20240116.2",
        urls = ["https://github.com/abseil/abseil-cpp/archive/20240116.2.zip"],
    )

    maybe(
        http_archive,
        name = "com_google_re2",
        sha256 = "eb2df807c781601c14a260a507a5bb4509be1ee626024cb45acbd57cb9d4032b",
        strip_prefix = "re2-2024-07-02",
        url = "https://github.com/google/re2/archive/2024-07-02.tar.gz",
        repo_mapping = {"@abseil-cpp": "@com_google_absl"},
    )
