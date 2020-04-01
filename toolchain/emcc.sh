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

set -euo pipefail

. $(dirname $0)/common.sh

emcc -s EMIT_EMSCRIPTEN_METADATA=1 -s STANDALONE_WASM=1 -s EXPORTED_FUNCTIONS=['_malloc','_free'] "$@"

# clang doesn't support `-no-canonical-system-headers` so sed it
# find the .d file in the args and fix it:

for arg in "$@"
do
    if [ ${arg: -2} == ".d" ]; then
        echo Fixing $arg
        sed -e 's%[^ ]*/external/emscripten_toolchain/upstream/emscripten/system/%external/emscripten_toolchain/upstream/emscripten/system/%' $arg > $arg.tmp
        mv $arg.tmp $arg
        # some zlib headers are treated as system headers
        sed -e 's%[^ ]*/external/zlib/%external/zlib/%' $arg > $arg.tmp
        mv $arg.tmp $arg
        break
    fi
done
