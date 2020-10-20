workspace(name = "proxy_wasm_cpp_sdk")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

BUILD_ZLIB = """filegroup(name = "zlib", srcs = glob(["**"]), visibility = ["//visibility:public"])"""

http_archive(
    name = "emscripten_toolchain",
    build_file = "//:emscripten-toolchain.BUILD",
    patch_cmds = [
        "./emsdk install 2.0.7",
        "./emsdk activate --embedded 2.0.7",
    ],
    strip_prefix = "emsdk-2.0.7",
    url = "https://github.com/emscripten-core/emsdk/archive/2.0.7.tar.gz",
    sha256 = "ce7a5c76e8b425aca874cea329fd9ac44b203b777053453b6a37b4496c5ce34f"
)

# required by com_google_protobuf
http_archive(
    name = "bazel_skylib",
    sha256 = "97e70364e9249702246c0e9444bccdc4b847bed1eb03c5a3ece4f83dfe6abc44",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/bazel-skylib/releases/download/1.0.2/bazel-skylib-1.0.2.tar.gz",
        "https://github.com/bazelbuild/bazel-skylib/releases/download/1.0.2/bazel-skylib-1.0.2.tar.gz",
    ],
)

load("@bazel_skylib//:workspace.bzl", "bazel_skylib_workspace")

bazel_skylib_workspace()

git_repository(
    name = "com_google_protobuf",
    commit = "655310ca192a6e3a050e0ca0b7084a2968072260",
    remote = "https://github.com/protocolbuffers/protobuf",
)

http_archive(
    name = "rules_proto",
    sha256 = "602e7161d9195e50246177e7c55b2f39950a9cf7366f74ed5f22fd45750cd208",
    strip_prefix = "rules_proto-97d8af4dc474595af3900dd85cb3a29ad28cc313",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/rules_proto/archive/97d8af4dc474595af3900dd85cb3a29ad28cc313.tar.gz",
        "https://github.com/bazelbuild/rules_proto/archive/97d8af4dc474595af3900dd85cb3a29ad28cc313.tar.gz",
    ],
)

load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")

rules_proto_dependencies()

rules_proto_toolchains()
