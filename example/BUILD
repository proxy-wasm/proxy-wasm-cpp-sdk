load("@proxy_wasm_cpp_sdk//bazel:defs.bzl", "proxy_wasm_cc_binary")

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

proxy_wasm_cc_binary(
    name = "http_proto_example_lite.wasm",
    srcs = ["http_proto_example.cc"],
    copts = ["-std=c++17"],
    protobuf = "lite",
)

proxy_wasm_cc_binary(
    name = "http_proto_example_full.wasm",
    srcs = ["http_proto_example.cc"],
    copts = ["-std=c++17"],
    protobuf = "full",
)

cc_library(
    name = "http_cache_filter_lib",
    srcs = ["http_cache_filter.cc", ],
    hdrs = ["memory_cache.h", "AuthConfigCheck.h", "auth_bypass_config.h", ],
    deps = [
        "@proxy_wasm_cpp_sdk//:proxy_wasm_intrinsics",  # Add the necessary dependency for proxy_wasm_intrinsics.h
        "@nlohmann_json//:json",
        "@com_google_re2//:re2", # RE2 for parsing auth-check-bypass-config.yaml
    ],
    copts = ["-std=c++17"],  # Enable exceptions
)

proxy_wasm_cc_binary(
    name = "http_cache_filter.wasm",
    srcs = ["http_cache_filter.cc"],
    deps = [
        ":http_cache_filter_lib",
    ], 
    copts = ["-std=c++17"],  # Enable exceptions
)
