ifdef NO_CONTEXT
  CPP_CONTEXT_LIB =
else
  CPP_CONTEXT_LIB = ${PROXY_WASM_CPP_SDK}/proxy_wasm_intrinsics.cc
endif

PROTOBUF ?= none
ifeq ($(PROTOBUF), full)
  PROTO_DEPS := protobuf
  PROTO_OPTS := -DPROXY_WASM_PROTOBUF_FULL=1
else ifeq ($(PROTOBUF), lite)
  PROTO_DEPS := protobuf-lite
  PROTO_OPTS := -DPROXY_WASM_PROTOBUF_LITE=1
else
  PROTO_DEPS :=
  PROTO_OPTS :=
endif

# Provide a list of libraries that the wasm depends on (absl_*, re2, etc).
WASM_DEPS ?=

# Determine dependency link options.
# NOTE: Strip out -pthread which RE2 claims to need...
PKG_CONFIG ?= pkg-config
PKG_CONFIG_PATH = ${EMSDK}/upstream/emscripten/cache/sysroot/lib/pkgconfig
WASM_LIBS = $(shell $(PKG_CONFIG) $(WASM_DEPS) $(PROTO_DEPS) \
	  --with-path=$(PKG_CONFIG_PATH) --libs | sed -e 's/-pthread //g')

debug-deps:
	# WASM_DEPS : ${WASM_DEPS}
	# WASM_LIBS : ${WASM_LIBS}
	# PROTO_DEPS: ${PROTO_DEPS}
	# PROTO_OPTS: ${PROTO_OPTS}

# TODO(mpwarres): Add Emscripten stack/heap size params in PR#174.
%.wasm %.wat: %.cc
	em++ --no-entry -sSTANDALONE_WASM -sEXPORTED_FUNCTIONS=_malloc \
		--std=c++17 -O3 -flto \
		--js-library ${PROXY_WASM_CPP_SDK}/proxy_wasm_intrinsics.js \
		-I${PROXY_WASM_CPP_SDK} \
		${CPP_CONTEXT_LIB} \
		${PROTO_OPTS} \
		${WASM_LIBS} \
		$*.cc -o $*.wasm

clean:
	rm *.wasm
