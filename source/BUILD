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
    ],
    hdrs = [
        "proxy_wasm_api.h",
        "proxy_wasm_common.h",
        "proxy_wasm_enums.h",
        "proxy_wasm_externs.h",
        "proxy_wasm_intrinsics.h",
    ],
    copts = ["-DPROXY_WASM_PROTOBUF_LITE=1"],
    visibility = ["//visibility:public"],
    deps = [
        "//api:proxy_wasm_intrinsics_lite_cc_proto",
        "@com_google_protobuf//:protobuf_lite",
    ],
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
    visibility = ["//visibility:public"],
    deps = [
        "//api:proxy_wasm_intrinsics_cc_proto",
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
