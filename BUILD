load("@rules_cc//cc:defs.bzl", "cc_library")

licenses(["notice"])  # Apache 2

package(default_visibility = ["//visibility:public"])

exports_files(["LICENSE"])

cc_library(
    name = "api_lib",
    hdrs = [
        "proxy_wasm_api.h",
        "proxy_wasm_externs.h",
    ],
    copts = ["-std=c++17"],
    deps = [
        ":common_lib",
        "@com_google_protobuf//:protobuf_lite",
    ],
)

cc_library(
    name = "common_lib",
    hdrs = [
        "proxy_wasm_common.h",
        "proxy_wasm_enums.h",
    ],
    copts = ["-std=c++17"],
)

cc_library(
    name = "proxy_wasm_intrinsics",
    srcs = [
        "proxy_wasm_intrinsics.cc",
    ],
    hdrs = [
        "proxy_wasm_api.h",
        "proxy_wasm_common.h",
        "proxy_wasm_enums.h",
        "proxy_wasm_externs.h",
        "proxy_wasm_intrinsics.h",
    ],
    copts = ["-std=c++17"],
    visibility = ["//visibility:public"],
)

# include lite protobuf support
cc_library(
    name = "proxy_wasm_intrinsics_lite",
    copts = ["-std=c++17"],
    defines = ["PROXY_WASM_PROTOBUF_LITE"],
    visibility = ["//visibility:public"],
    deps = [
        ":proxy_wasm_intrinsics",
        "@com_google_protobuf//:protobuf_lite",
    ],
)

# include full protobuf support
cc_library(
    name = "proxy_wasm_intrinsics_full",
    copts = ["-std=c++17"],
    defines = ["PROXY_WASM_PROTOBUF_FULL"],
    visibility = ["//visibility:public"],
    deps = [
        ":proxy_wasm_intrinsics",
        "@com_google_protobuf//:protobuf",
    ],
)

filegroup(
    name = "proxy_wasm_intrinsics_js",
    srcs = [
        "proxy_wasm_intrinsics.js",
    ],
    visibility = ["//visibility:public"],
)
