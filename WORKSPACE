workspace(name = "proxy_wasm_cpp_sdk")

load("@proxy_wasm_cpp_sdk//bazel:repositories.bzl", "proxy_wasm_cpp_sdk_repositories")

proxy_wasm_cpp_sdk_repositories()

load("@proxy_wasm_cpp_sdk//bazel:dependencies.bzl", "proxy_wasm_cpp_sdk_dependencies")

proxy_wasm_cpp_sdk_dependencies()

load("@proxy_wasm_cpp_sdk//bazel:dependencies_extra.bzl", "proxy_wasm_cpp_sdk_dependencies_extra")

proxy_wasm_cpp_sdk_dependencies_extra()

# Add nlohmann_json repository
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "nlohmann_json",
    urls = ["https://github.com/nlohmann/json/archive/refs/tags/v3.11.3.tar.gz"],
    strip_prefix = "json-3.11.3",
    #sha256 = "b1a1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1",
    build_file_content = """
cc_library(
    name = "json",
    hdrs = glob(["include/**"]),
    includes = ["include"],
    visibility = ["//visibility:public"],
)
""",
)

http_archive(
    name = "com_google_re2",
    strip_prefix = "re2-2024-07-02",  # Strip the prefix correctly as per the repo structure
    url = "https://github.com/google/re2/archive/refs/tags/2024-07-02.tar.gz",  # URL of RE2 archive
)

# Fetch Abseil
#http_archive(
#    name = "abseil-cpp",
#    url = "https://github.com/abseil/abseil-cpp/archive/refs/tags/20240116.3.tar.gz",  # Updated to the new version
#    strip_prefix = "abseil-cpp-20240116.3",
#)

# YAML-CPP
http_archive(
    name = "yaml_cpp",
    url = "https://github.com/jbeder/yaml-cpp/archive/refs/tags/0.8.0.tar.gz",
    strip_prefix = "yaml-cpp-0.8.0",
)
