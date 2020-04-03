load("//:bazel/api_build_system.bzl", "api_proto_package")

licenses(["notice"])  # Apache 2

api_proto_package(
    name = "proxy_wasm_intrinsics",
    srcs = [
        "proxy_wasm_intrinsics.proto",
    ],
)

api_proto_package(
    name = "proxy_wasm_intrinsics_lite",
    srcs = [
        "proxy_wasm_intrinsics_lite.proto",
        "struct_lite.proto",
    ],
)
