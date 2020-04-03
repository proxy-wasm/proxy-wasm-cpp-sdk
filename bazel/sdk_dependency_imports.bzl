load("@bazel_skylib//:workspace.bzl", "bazel_skylib_workspace")
load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")

def sdk_dependency_imports():
    bazel_skylib_workspace()
    rules_proto_dependencies()
    rules_proto_toolchains()
