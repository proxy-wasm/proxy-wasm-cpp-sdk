load("//:bazel/wasm_build_system.bzl", "wasm_binary")

licenses(["notice"])

package(default_visibility = ["//visibility:public"])

wasm_binary(
    name = "example_base",
)

wasm_binary(
    name = "example_lite",
    lite = True,
)
