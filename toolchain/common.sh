#!/bin/bash
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

# emsdk_env.sh\emcc doesn't like the bazel sandbox
# specifically, emsdk_env.sh seems to try to `cd` and `cd` back which doesn't work well
if [[ "$OSTYPE" == "linux-gnu" ]]; then
cd -P /proc/self/cwd
fi

TOOLCHAIN_ROOT=${EXT_BUILD_ROOT:-$PWD}

export NODE_JS=''
export EMSCRIPTEN_ROOT="${TOOLCHAIN_ROOT}/external/emscripten_toolchain"
export SPIDERMONKEY_ENGINE=''
export EM_EXCLUSIVE_CACHE_ACCESS=1
export EMCC_SKIP_SANITY_CHECK=1
export EMCC_WASM_BACKEND=1

#echo "$(pwd)/external/emscripten_toolchain/emsdk_env.sh"
#realpath "external/emscripten_toolchain/emsdk_env.sh"
source "${EMSCRIPTEN_ROOT}/emsdk_env.sh"

 # the emscripten sdk does some path comparison, so make EM_CACHE an absolute path to make it work. 
mkdir -p "${TOOLCHAIN_ROOT}/tmp/emscripten_cache"
export EM_CACHE="${TOOLCHAIN_ROOT}/tmp/emscripten_cache"
export TEMP_DIR="${TOOLCHAIN_ROOT}/tmp"
