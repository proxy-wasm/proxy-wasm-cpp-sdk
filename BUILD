licenses(["notice"])  # Apache 2

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "api_lib",
    hdrs = ["proxy_wasm_api.h"],
)

cc_library(
    name = "common_lib",
    hdrs = [
        "proxy_wasm_common.h",
        "proxy_wasm_enums.h",
    ],
)

cc_library(
    name = "proxy_wasm_intrinsics_lite",
    srcs = [
        "proxy_wasm_intrinsics.cc",
        "proxy_wasm_intrinsics_lite.pb.cc",
        "struct_lite.pb.cc",
    ],
    copts = [ "-DPROXY_WASM_PROTOBUF_LITE=1" ],
    hdrs = [
        "proxy_wasm_api.h",
        "proxy_wasm_common.h",
        "proxy_wasm_enums.h",
        "proxy_wasm_externs.h",
        "proxy_wasm_intrinsics.h",
        "proxy_wasm_intrinsics_lite.pb.h",
        "struct_lite.pb.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "@com_google_protobuf//:protobuf_lite",
    ],
)

cc_library(
    name = "proxy_wasm_intrinsics",
    srcs = [
        "proxy_wasm_intrinsics.cc",
        "proxy_wasm_intrinsics.pb.cc",
    ],
    hdrs = [
        "proxy_wasm_api.h",
        "proxy_wasm_common.h",
        "proxy_wasm_enums.h",
        "proxy_wasm_externs.h",
        "proxy_wasm_intrinsics.h",
        "proxy_wasm_intrinsics.pb.h",
        "struct_lite.pb.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "@com_google_protobuf//:protobuf",
    ],
)

filegroup(
    name = "jslib",
    srcs = [
        "proxy_wasm_intrinsics.js",
    ],
    visibility = ["//visibility:public"],
)
