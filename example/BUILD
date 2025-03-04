load("@proxy_wasm_cpp_sdk//bazel:defs.bzl", "proxy_wasm_cc_binary")
load("@rules_cc//cc:defs.bzl", "cc_proto_library")
load("@rules_proto//proto:defs.bzl", "proto_library")

licenses(["notice"])  # Apache 2

proxy_wasm_cc_binary(
    name = "http_wasm_example.wasm",
    srcs = ["http_wasm_example.cc"],
    copts = ["-std=c++17"],
)

proxy_wasm_cc_binary(
    name = "http_re_example.wasm",
    srcs = ["http_re_example.cc"],
    copts = ["-std=c++17"],
    deps = ["@com_google_re2//:re2"],
)

proxy_wasm_cc_binary(
    name = "http_proto_example_none.wasm",
    srcs = ["http_proto_example.cc"],
    copts = ["-std=c++17"],
)

proto_library(
    name = "example_proto",
    srcs = ["example.proto"],
    deps = ["@com_google_protobuf//:struct_proto"],
)

cc_proto_library(
    name = "example_proto_cc",
    deps = [":example_proto"],
)

cc_library(
    name = "http_proto_example_lite_lib",
    srcs = ["http_proto_example.cc"],
    copts = ["-std=c++17"],
    deps = [
        ":example_proto_cc",
        "@proxy_wasm_cpp_sdk//:proxy_wasm_intrinsics_lite",
    ],
    alwayslink = 1,
)

proxy_wasm_cc_binary(
    name = "http_proto_example_lite.wasm",
    deps = [":http_proto_example_lite_lib"],
)

cc_library(
    name = "http_proto_example_full_lib",
    srcs = ["http_proto_example.cc"],
    copts = ["-std=c++17"],
    deps = [
        ":example_proto_cc",
        "@proxy_wasm_cpp_sdk//:proxy_wasm_intrinsics_full",
    ],
    alwayslink = 1,
)

proxy_wasm_cc_binary(
    name = "http_proto_example_full.wasm",
    deps = [":http_proto_example_full_lib"],
)
