def wasm_binary(
        name = "binary",
        out = "",
        lite = False,
        srcs = []):
    if out == "":
        out = name + ".wasm"
