# Proxy-Wasm C++ SDK Build Instructions

The C++ SDK has dependencies on specific versions of the C++ WebAssembly
toolchain [Emscripten](https://emscripten.org) and the protobuf library,
therefore use of a Docker image is recommended.

## Docker

A Dockerfile for the C++ SDK is provided in [Dockerfile-sdk](../Dockerfile-sdk).

It can built in this repository's root directory by:

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
git checkout 3.1.67

./emsdk install 3.1.67
./emsdk activate 3.1.67

source ./emsdk_env.sh
```

It is possible later versions will work, e.g.

```bash
./emsdk update-tags
./emsdk install latest
./emsdk activate latest
```

However 3.1.67 is known to work.

### Rebuilding the libprotobuf.a files

To build the protobuf static libraries for use in your proxy-wasm wasm module,
if you need them, you may use Emscripten in the same way sdk\_container.sh does
it:

```bash
git clone https://github.com/protocolbuffers/protobuf protobuf-wasm
cd protobuf-wasm
git checkout v3.9.1
git submodule update --init --recursive
./autogen.sh
emconfigure ./configure --disable-shared CXXFLAGS="-O3 -flto"
emmake make
cd ..
cp protobuf-wasm/src/.libs/libprotobuf-lite.a ${CPP_API}/libprotobuf-lite.a
cp protobuf-wasm/src/.libs/libprotobuf.a ${CPP_API}/libprotobuf.a
```

Note: ensure /usr/local/bin is in your path.
