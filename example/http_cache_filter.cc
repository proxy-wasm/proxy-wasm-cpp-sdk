// Copyright 2016-2020 Envoy Project Authors
// Copyright 2020 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <string>
#include <string_view>

#include "proxy_wasm_intrinsics.h"

// For respose cache
#include "memory_cache.h"
// Define the TTLCache type using std::string as Key and int as Value with LRU policy
//using MyTTLCache = TTLCache<std::string, int, caches::LRUCachePolicy>;
using namespace memory_cache;

class ExampleRootContext : public RootContext {
public:
  explicit ExampleRootContext(uint32_t id, std::string_view root_id) : 
             RootContext(id, root_id) {}

  bool onStart(size_t) override;
  bool onConfigure(size_t) override;
  //void onTick() override;

  MemoryCache& getCache() {
    static std::shared_ptr<MemoryCache> cache_instance = std::make_shared<MemoryCache>(100, 30);
    LOG_INFO("Address of cache_: " + std::to_string(reinterpret_cast<uintptr_t>(cache_instance.get())));
    return *cache_instance;
  }
};

class ExampleContext : public Context {
public:
  explicit ExampleContext(uint32_t id, RootContext *root) : Context(id, root) {}

  //void onCreate() override;
  FilterHeadersStatus onRequestHeaders(uint32_t headers, bool end_of_stream) override;
  FilterDataStatus onRequestBody(size_t body_buffer_length, bool end_of_stream) override;
  FilterHeadersStatus onResponseHeaders(uint32_t headers, bool end_of_stream) override;
  FilterMetadataStatus onResponseMetadata(uint32_t elements) override;
  //FilterDataStatus onResponseBody(size_t body_buffer_length, bool end_of_stream) override;
  //FilterTrailersStatus onResponseTrailers(uint32_t trailers) override;
  //void onDone() override;
  //void onLog() override;
  //void onDelete() override;

  private:
    std::string auth_key_;
};
static RegisterContextFactory register_ExampleContext(CONTEXT_FACTORY(ExampleContext),
                                                      ROOT_FACTORY(ExampleRootContext));

bool ExampleRootContext::onStart(size_t) {
  LOG_TRACE("onStart");
  return true;
}

bool ExampleRootContext::onConfigure(size_t) {
  LOG_TRACE("onConfigure");
  proxy_set_tick_period_milliseconds(1000); // 1 sec
  return true;
}

//void ExampleRootContext::onTick() { LOG_TRACE("onTick"); }
//void ExampleContext::onCreate() { LOG_WARN(std::string("onCreate " + std::to_string(id()))); }

FilterHeadersStatus ExampleContext::onRequestHeaders(uint32_t, bool) {
  LOG_INFO(std::string("onRequestHeaders ") + std::to_string(id()));
  /*auto result = getRequestHeaderPairs();
  auto pairs = result->pairs();
  LOG_INFO(std::string("headers: ") + std::to_string(pairs.size()));
  for (auto &p : pairs) {
    LOG_INFO(std::string(p.first) + std::string(" -> ") + std::string(p.second));
  }*/
  replaceRequestHeader("x-skip-ext-authz", "false");


  // Store the x-verkada-auth header value
  auto auth_header = getRequestHeader("x-verkada-auth");
  if (auth_header) {
    auth_key_ = auth_header->toString();
    
    // Check cache
    auto* root_context = static_cast<ExampleRootContext*>(root());
    auto& cache = root_context->getCache();

    // Check if the key is in the cache
    auto cached_value = cache.Get(auth_key_.c_str());
    if (cached_value) {
      LOG_INFO("Cache hit for key: " + auth_key_ + ", cached status: " + std::to_string(*cached_value));
      
      // Set the cached status as the response header
      addResponseHeader(":status", std::to_string(*cached_value));
      replaceRequestHeader("x-skip-ext-authz", "true");

      return FilterHeadersStatus::Continue;
    } else {
      LOG_INFO("Cache miss for key: " + auth_key_);    }
  }

  return FilterHeadersStatus::Continue;
}

FilterHeadersStatus ExampleContext::onResponseHeaders(uint32_t, bool) {
  LOG_WARN(std::string("onResponseHeaders ") + std::to_string(id()));
  
  /*
  auto result = getResponseHeaderPairs();
  auto pairs = result->pairs();
  LOG_INFO(std::string("headers: ") + std::to_string(pairs.size()));
  for (auto &p : pairs) {
    LOG_INFO(std::string(p.first) + std::string(" -> ") + std::string(p.second));
  }*/
  // addResponseHeader("X-Wasm-custom", "FOO");
  // replaceResponseHeader("content-type", "text/plain; charset=utf-8");
  // removeResponseHeader("content-length");

  auto* root_context = static_cast<ExampleRootContext*>(root());
  auto& cache = root_context->getCache();

  // Cache the result of the next filter (which should be the ext_authz filter)
  auto status_code = getResponseHeader(":status");
  LOG_WARN(std::string("status_code: ") + status_code->toString());
  if (status_code) {
    int status = std::stoi(status_code->toString());
    cache.Insert(auth_key_, status);
    LOG_INFO("Caching key: " + auth_key_ + ", status: " + std::to_string(status));
    // Loop 10 times and get the value from the cache
  for (int i = 0; i < 10; ++i) {
    auto cached_value = cache.Get(auth_key_);
    if (cached_value) {
      LOG_INFO("Loop " + std::to_string(i) + ": Cache hit for key: " + auth_key_ + ", cached status: " + std::to_string(*cached_value));
    } else {
      LOG_INFO("Loop " + std::to_string(i) + ": Cache miss for key: " + auth_key_);
    }
  }
  }

  return FilterHeadersStatus::Continue;
}

  FilterMetadataStatus ExampleContext::onResponseMetadata(uint32_t elements) {
    LOG_WARN(std::string("onResponseMetadata ") + std::to_string(id()) + " elements: " + std::to_string(elements));
    return FilterMetadataStatus::Continue;
  }

FilterDataStatus ExampleContext::onRequestBody(size_t body_buffer_length,
                                               bool /* end_of_stream */) {
  auto body = getBufferBytes(WasmBufferType::HttpRequestBody, 0, body_buffer_length);
  LOG_ERROR(std::string("onRequestBody ") + std::string(body->view()));
  return FilterDataStatus::Continue;
}

/*FilterDataStatus ExampleContext::onResponseBody(size_t body_buffer_length,
                                                bool end_of_stream) {
  LOG_WARN(std::string("onResponseBody ") + std::to_string(id()));
  setBuffer(WasmBufferType::HttpResponseBody, 0, 12, "Hello, world");
  return FilterDataStatus::Continue;
}*/

/*FilterTrailersStatus ExampleContext::onResponseTrailers(uint32_t trailers) {
  LOG_WARN(std::string("onResponseTrailers ") + std::to_string(id()));
  return FilterTrailersStatus::Continue;
}*/

//void ExampleContext::onDone() { LOG_WARN(std::string("onDone " + std::to_string(id()))); }

//void ExampleContext::onLog() { LOG_WARN(std::string("onLog " + std::to_string(id()))); }

//void ExampleContext::onDelete() { LOG_WARN(std::string("onDelete " + std::to_string(id()))); }
