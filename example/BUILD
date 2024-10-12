load("@proxy_wasm_cpp_sdk//bazel:defs.bzl", "proxy_wasm_cc_binary")

licenses(["notice"])  # Apache 2

proxy_wasm_cc_binary(
    name = "http_wasm_example.wasm",
    srcs = ["http_wasm_example.cc"],
    copts = ["-std=c++17"],
    deps = ["@com_google_re2//:re2"],
)

proxy_wasm_cc_binary(
    name = "http_wasm_example_with_protobuf_lite.wasm",
    srcs = ["http_wasm_example.cc"],
    copts = ["-std=c++17"],
    protobuf = "lite",
    deps = ["@com_google_re2//:re2"],
)

proxy_wasm_cc_binary(
    name = "http_wasm_example_with_protobuf_full.wasm",
    srcs = ["http_wasm_example.cc"],
    copts = ["-std=c++17"],
    protobuf = "full",
    deps = ["@com_google_re2//:re2"],
)
