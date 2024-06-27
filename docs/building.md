# Proxy-Wasm C++ SDK Build Instructions

The C++ SDK has dependencies on specific versions of the C++ WebAssembly
toolchain [Emscripten](https://emscripten.org) and the protobuf library,
therefore use of a Docker image is recommended.

## Docker

A Dockerfile for the C++ SDK is provided in [Dockerfile-sdk](Dockerfile-sdk).

It can built in this directory by:

```bash
docker build -t wasmsdk:v2 -f Dockerfile-sdk .
```

The docker image can be used for compiling C++ plugin code into Wasm modules.

### Creating a project for use with the Docker build image

Create a directory with your source files and a Makefile:

```makefile
PROXY_WASM_CPP_SDK=/sdk

all: myproject.wasm

include ${PROXY_WASM_CPP_SDK}/Makefile.base_lite
```

Source file (myproject.cc):

```c++
#include <string>
#include <unordered_map>

#include "proxy_wasm_intrinsics.h"

class ExampleContext : public Context {
public:
  explicit ExampleContext(uint32_t id, RootContext* root) : Context(id, root) {}

  FilterHeadersStatus onRequestHeaders(uint32_t headers, bool end_of_stream) override;
  void onDone() override;
};
static RegisterContextFactory register_ExampleContext(CONTEXT_FACTORY(ExampleContext));

FilterHeadersStatus ExampleContext::onRequestHeaders(uint32_t headers, bool end_of_stream) {
  logInfo(std::string("onRequestHeaders ") + std::to_string(id()));
  auto path = getRequestHeader(":path");
  logInfo(std::string("header path ") + std::string(path->view()));
  return FilterHeadersStatus::Continue;
}

void ExampleContext::onDone() { logInfo("onDone " + std::to_string(id())); }
```

### Compiling with the Docker build image

Run docker:

```bash
docker run -v $PWD:/work -w /work  wasmsdk:v2 /build_wasm.sh
```

### Caching the standard libraries

The first time that emscripten runs it will generate the standard libraries.  To
cache these in the docker image, after the first successful compilation (e.g
myproject.cc above), commit the image with the standard libraries:

```bash
docker commit `docker ps -l | grep wasmsdk:v2 | awk '{print $1}'` wasmsdk:v2
```

This will save time on subsequent compiles.

### Using the SDK from a newer/specific version of Envoy

To use a newer/specific version of the SDK (e.g. from the version of Envoy you
are going to deploy the WebAssembly module to), bind that volume and use it in
the Makefile.

Here is an example Makefile referencing the SDK at `../envoy/api/wasm/cpp` and
mounted as `sdk` in the `/work` directory:

```makefile
PROXY_WASM_CPP_SDK=/work/sdk

all: myproject.wasm

include ${PROXY_WASM_CPP_SDK}/Makefile.base_lite
```

Run docker pointing to Envoy sources in a directory parallel (at the same level)
as your project directory:

```bash
docker run -v $PWD:/work -v $PWD/../envoy/api/wasm/cpp:/work/sdk -w /work  wasmsdk:v2 bash /build_wasm.sh
```

### Using Abseil from the Docker image

Abseil (optionally) is built in /root/abseil and can be used. Note that the
Abseil containers (e.g. `absl::flat_hash_set`) exercise many syscalls which are
not supported. Consequentially individual files should be pulled in which are
relatively self contained (e.g. `strings`). Example customized Makefile:

```makefile
PROXY_WASM_CPP_SDK=/sdk
CPP_API:=${PROXY_WASM_CPP_SDK}
CPP_CONTEXT_LIB = ${CPP_API}/proxy_wasm_intrinsics.cc
ABSL = /root/abseil-cpp
ABSL_CPP = ${ABSL}/absl/strings/str_cat.cc ${ABSL}/absl/strings/str_split.cc ${ABSL}/absl/strings/numbers.cc ${ABSL}/absl/strings/ascii.cc

all: plugin.wasm

%.wasm %.wat: %.cc ${CPP_API}/proxy_wasm_intrinsics.h ${CPP_API}/proxy_wasm_enums.h ${CPP_API}/proxy_wasm_externs.h ${CPP_API}/proxy_wasm_api.h ${CPP_API}/proxy_wasm_intrinsics.js ${CPP_CONTEXT_LIB}
        ls /root
                em++ --no-entry -s EXPORTED_FUNCTIONS=['_malloc'] --std=c++17 -O3 -flto -I${CPP_API} -I${CPP_API}/google/protobuf -I/usr/local/include -I${ABSL} --js-library ${CPP_API}/proxy_wasm_intrinsics.js ${ABSL_CPP} $*.cc ${CPP_API}/proxy_wasm_intrinsics.pb.cc ${CPP_CONTEXT_LIB} ${CPP_API}/libprotobuf.a -o $*.wasm
```

Precompiled Abseil libraries are also available, so the above can also be done
as:

```makefile
PROXY_WASM_CPP_SDK=/sdk
CPP_API:=${PROXY_WASM_CPP_SDK}
CPP_CONTEXT_LIB = ${CPP_API}/proxy_wasm_intrinsics.cc
ABSL = /root/abseil-cpp
ABSL_LIBS = ${ABSL}/absl/strings/libabsl_strings.a ${ABSL}/absl/strings/libabsl_strings_internal.a  ${ABSL}/absl/strings/libabsl_str_format_internal.a

all: plugin.wasm

%.wasm %.wat: %.cc ${CPP_API}/proxy_wasm_intrinsics.h ${CPP_API}/proxy_wasm_enums.h ${CPP_API}/proxy_wasm_externs.h ${CPP_API}/proxy_wasm_api.h ${CPP_API}/proxy_wasm_intrinsics.js ${CPP_CONTEXT_LIB}
        ls /root
                em++ --no-entry -s EXPORTED_FUNCTIONS=['_malloc'] --std=c++17 -O3 -flto -I${CPP_API} -I${CPP_API}/google/protobuf -I/usr/local/include -I${ABSL} --js-library ${CPP_API}/proxy_wasm_intrinsics.js  $*.cc ${CPP_API}/proxy_wasm_intrinsics.pb.cc ${CPP_CONTEXT_LIB} ${CPP_API}/libprotobuf.a ${ABSL_LIBS} -o $*.wasm
```

### Ownership of the resulting .wasm files

The compiled files may be owned by root.  To chown them, add the follow lines to
the Makefile and docker invocation:

```makefile
PROXY_WASM_CPP_SDK=/sdk

all: myproject.wasm
  chown ${uid}.${gid} $^

include ${PROXY_WASM_CPP_SDK}/Makefile.base_lite
```

Invocation file (e.g. build.sh):

```bash
#!/bin/bash
docker run -e uid="$(id -u)" -e gid="$(id -g)" -v $PWD:/work -w /work wasmsdk:v2 /build_wasm.sh
```

## Dependencies for building Wasm modules:

If you do not wish to use the Docker image, the dependencies can be installed by
script (sdk\_container.sh), or by hand.

### protobuf v3.9.1

You must install the version of protobuf on your build system that matches the
libprotobuf.a files (without any patches) so that the generated code matches the
.a library.  Currently this is based on tag v3.9.1 of
https://github.com/protocolbuffers/protobuf.

```bash
git clone https://github.com/protocolbuffers/protobuf
cd protobuf
git checkout v3.9.1
git submodule update --init --recursive
./autogen.sh
./configure
make
make check
sudo make install
```

### Emscripten

```bash
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
./emsdk update-tags
./emsdk install 3.1.7
./emsdk activate 3.1.7

source ./emsdk_env.sh
```

It is possible later versions will work, e.g.

```bash
./emsdk update-tags
./emsdk install latest
./emsdk activate latest
```

However 3.1.7 is known to work.

### Rebuilding the libprotobuf.a files

If want to rebuild the libprotobuf.a files or use a different version see the
instructions at https://github.com/kwonoj/protobuf-wasm. Commit
4bba8b2f38b5004f87489642b6ca4525ae72fe7f works for protobuf v3.9.x.

```bash
git clone https://github.com/protocolbuffers/protobuf protobuf-wasm
cd protobuf-wasm
git checkout v3.9.1
git clone https://github.com/kwonoj/protobuf-wasm wasm-patches
cd wasm-patches && git checkout 4bba8b2f38b5004f87489642b6ca4525ae72fe7f && cd ..
git apply wasm-patches/*.patch
./autogen.sh
emconfigure ./configure --disable-shared CXXFLAGS="-O3 -flto"
emmake make
cd ..
cp protobuf-wasm/src/.libs/libprotobuf-lite.a ${CPP_API}/libprotobuf-lite.a
cp protobuf-wasm/src/.libs/libprotobuf.a ${CPP_API}/libprotobuf.a
```

Note: ensure /usr/local/bin is in your path.
