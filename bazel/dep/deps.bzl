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

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")

def wasm_dependencies():
    _http_archive(
        name = "emscripten_toolchain",
        build_file = "@proxy_wasm_cpp_sdk//:emscripten-toolchain.BUILD",
        patch_cmds = [
            "./emsdk install 2.0.7",
            "./emsdk activate --embedded 2.0.7",
        ],
        strip_prefix = "emsdk-2.0.7",
        url = "https://github.com/emscripten-core/emsdk/archive/2.0.7.tar.gz",
        sha256 = "ce7a5c76e8b425aca874cea329fd9ac44b203b777053453b6a37b4496c5ce34f"
    )

    _http_archive(
        name = "com_google_protobuf",
        sha256 = "77ad26d3f65222fd96ccc18b055632b0bfedf295cb748b712a98ba1ac0b704b2",
        strip_prefix = "protobuf-3.17.3",
        url = "https://github.com/protocolbuffers/protobuf/releases/download/v3.17.3/protobuf-all-3.17.3.tar.gz",
    )

def _http_archive(name, **kwargs):
    existing_rule_keys = native.existing_rules().keys()
    if name in existing_rule_keys:
        # This repository has already been defined.
        return

    http_archive(
        name = name,
        **kwargs
    )
