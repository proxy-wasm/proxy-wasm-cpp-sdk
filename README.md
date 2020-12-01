# WebAssembly for Proxies (C++ SDK)

[![Build Status][build-badge]][build-link]
[![Apache 2.0 License][license-badge]][license-link]

The SDK uses [bazel](https://bazel.build/) for its build. 


## Creating a project for use

Create a directory with your `WORKSPACE` file, source files, and `BUILD` files:

`WORKSPACE`:

```
workspace(name = "my_extension")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Replace '<CPP-SDK-SHA>' with actual SHA from github.
http_archive(
    name = "proxy_wasm_cpp_sdk",
    strip_prefix = "proxy-wasm-cpp-sdk-<CPP-SDK-SHA>",
    url = "https://github.com/proxy-wasm/proxy-wasm-cpp-sdk/archive/<CPP-SDK-SHA>.tar.gz",
)

load("@proxy_wasm_cpp_sdk//bazel/dep:deps.bzl", "wasm_dependencies")

wasm_dependencies()

load("@proxy_wasm_cpp_sdk//bazel/dep:deps_extra.bzl", "wasm_dependencies_extra")

wasm_dependencies_extra()
```

Source file (`myplugin.cc`):

```
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

`BUILD`:

```
load("@proxy_wasm_cpp_sdk//bazel/wasm:wasm.bzl", "wasm_cc_binary")

wasm_cc_binary(
    name = "myplugin.wasm",
    srcs = [
        "myplugin.cc",
    ],
    deps = [
        "@proxy_wasm_cpp_sdk//:proxy_wasm_intrinsics",
    ],
)
```

## Compiling with Bazel

It is recommended to use Bazelisk installed as Bazel:

On Linux, run the following commands:

```
sudo wget -O /usr/local/bin/bazel https://github.com/bazelbuild/bazelisk/releases/latest/download/bazelisk-linux-amd64
sudo chmod +x /usr/local/bin/bazel
```

Several dependencies are needs in order to build a C++ WebAssembly plugins with Bazel.

on Unbuntu, run the following command:

```
sudo apt-get install gcc curl python3
```

Then run the following Bazel command:

```
bazel build //:myplugin.wasm
```

After the command finishes, you should be able to find `myplugin.wasm` file under `./bazel-bin` folder.

### Compiling with the Docker build image

A Dockerfile for the C++ SDK is provided in sdk.Dockerfile.

It can built in this directory by:

```
docker build -t wasmsdk -f sdk.Dockerfile .
```

The docker image can be used for compiling wasm files:

```bash
docker run \
-u $(id -u):$(id -g) \
-e HOME="/home" \
-e USER=${USER} \
--mount type=bind,source=${PWD},target=/work \
-w /work \
wasmsdk \
/bin/bash -lc \
'bazel build //:myplugin.wasm && cp bazel-bin/myplugin.wasm myplugin.wasm && bazel clean --expunge'
```

After the command finishes, you should be able to find `myplugin.wasm` file along with source files.

[build-badge]: https://github.com/proxy-wasm/proxy-wasm-cpp-sdk/workflows/C++/badge.svg?branch=master
[build-link]: https://github.com/proxy-wasm/proxy-wasm-cpp-sdk/actions?query=workflow%3AC%2B%2B+branch%3Amaster
[license-badge]: https://img.shields.io/github/license/proxy-wasm/proxy-wasm-cpp-sdk
[license-link]: https://github.com/proxy-wasm/proxy-wasm-cpp-sdk/blob/master/LICENSE
