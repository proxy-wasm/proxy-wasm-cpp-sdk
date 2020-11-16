load("@bazel_skylib//:workspace.bzl", "bazel_skylib_workspace")
load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")

# Wasm deps that rely on a first stage of dependency loading in wasm_dependencies().
def wasm_dependencies_extra():
    bazel_skylib_workspace()
    rules_proto_dependencies()
    rules_proto_toolchains()
