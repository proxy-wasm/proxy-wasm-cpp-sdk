load("@rules_cc//cc:defs.bzl", "cc_proto_library")
load("@rules_proto//proto:defs.bzl", "proto_library")

_CC_PROTO_SUFFIX = "_cc_proto"
_COMMON_PROTO_DEPS = [
    "@com_google_protobuf//:any_proto",
    "@com_google_protobuf//:duration_proto",
    "@com_google_protobuf//:empty_proto",
    "@com_google_protobuf//:struct_proto",
]

def api_proto_package(
        name = "pkg",
        srcs = [],
        deps = [],
        visibility = ["//visibility:public"]):
    if srcs == []:
        srcs = native.glob(["*.proto"])

    proto_library(
        name = name,
        srcs = srcs,
        deps = deps + _COMMON_PROTO_DEPS,
        visibility = visibility,
    )

    relative_name = ":" + name
    cc_proto_library_name = name + _CC_PROTO_SUFFIX

    cc_proto_library(
        name = cc_proto_library_name,
        deps = [relative_name],
        visibility = ["//visibility:public"],
    )
