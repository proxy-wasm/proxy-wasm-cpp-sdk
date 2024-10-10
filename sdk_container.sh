#!/bin/bash
# Copyright 2016-2019 Envoy Project Authors
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

set -e

# basics
export DEBIAN_FRONTEND=noninteractive
apt-get update
apt-get upgrade -y
apt-get autoremove -y
apt-get clean
apt-get install -y --no-install-recommends ca-certificates git autoconf autotools-dev automake libtool cmake python-is-python3 zlib1g-dev make xz-utils libzstd-dev

# The specific version of GCC does not actually matter as long as it's confirmed to work.
# That's why we explicitly pin gcc version (in this case to gcc 13) - it's the version
# which was tested to work.
apt-get install -y --no-install-recommends gcc-13 g++-13 cpp-13
export CC=gcc-13
export CXX=g++-13
export CPP=cpp-13

NUM_CPUS=$(nproc)
JOBS=$((NUM_CPUS>1 ? NUM_CPUS-1 : NUM_CPUS))

# get $HOME
cd

# specific version of protobufs to match the pre-compiled support libraries
git clone https://github.com/protocolbuffers/protobuf
cd protobuf
git checkout v3.9.1
git submodule update --init --recursive
./autogen.sh
./configure
make -j $JOBS
make check
make install
cd
rm -rf protobuf

# This makes sure that installed dynamic libraries are visible to the dynamic
# linker, because it seems like make install does not take care of that
ldconfig

# emscripten
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
git checkout 3.1.67
./emsdk install --shallow 3.1.67
./emsdk activate 3.1.67
source ./emsdk_env.sh
cd

git clone https://github.com/protocolbuffers/protobuf protobuf-wasm
cd protobuf-wasm
git checkout v3.9.1
git submodule update --init --recursive
./autogen.sh
emconfigure ./configure --disable-shared CXXFLAGS="-O3 -flto"
emmake make -j $JOBS
cd

cp protobuf-wasm/src/.libs/libprotobuf-lite.a /sdk/libprotobuf-lite.a
cp protobuf-wasm/src/.libs/libprotobuf.a /sdk/libprotobuf.a
rm -rf protobuf-wasm

# abseil (optional)
git clone https://github.com/abseil/abseil-cpp
cd abseil-cpp
git checkout 4447c7562e3bc702ade25105912dce503f0c4010 -b lts20240722 # Abseil LTS release 20240722.0
# TODO -DSTANDALONE_WASM -sSTANDALONE_WASM ?
emcmake cmake -DCMAKE_CXX_STANDARD=17 "."
emmake make -j $JOBS
cd

