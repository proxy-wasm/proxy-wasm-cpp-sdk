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

#include <nlohmann/json.hpp>
#include <string>
#include <string_view>

#include "proxy_wasm_intrinsics.h"

// For respose cache
#include "memory_cache.h"
// Define the TTLCache type using std::string as Key and int as Value with LRU policy
//using MyTTLCache = TTLCache<std::string, int, caches::LRUCachePolicy>;

using json = nlohmann::json;
using namespace memory_cache;

class ExampleRootContext : public RootContext {
public:
  explicit ExampleRootContext(uint32_t id, std::string_view root_id) : 
             RootContext(id, root_id) {}

  bool onStart(size_t) override;
  bool onConfigure(size_t) override;
  //void onTick() override;

  MemoryCache& getCache() {
    static std::shared_ptr<MemoryCache> cache_instance = std::make_shared<MemoryCache>(1000000, 3600);
    return *cache_instance;
  }
};

class ExampleContext : public Context {
public:
  explicit ExampleContext(uint32_t id, RootContext *root) : Context(id, root) {}

  //void onCreate() override;
  FilterHeadersStatus onRequestHeaders(uint32_t headers, bool end_of_stream) override;
  //FilterDataStatus onRequestBody(size_t body_buffer_length, bool end_of_stream) override;
  //FilterHeadersStatus onResponseHeaders(uint32_t headers, bool end_of_stream) override;
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
  LOG_INFO("onStart");
  return true;
}

bool ExampleRootContext::onConfigure(size_t configuration_size) {
  LOG_INFO("onConfigure");
  
  // Get configuration parameters using getBufferBytes
  /*
  auto config_buffer = getBufferBytes(WasmBufferType::PluginConfiguration, 0, configuration_size);
  if (config_buffer) {
    std::string config_json = config_buffer->toString();
    LOG_INFO("Configuration: " + config_json);

    // Parse the configuration JSON
    auto config_obj = json::parse(config_json);
    host_ = config_obj["host"].get<std::string>();
    path_ = config_obj["path"].get<std::string>();
    scheme_ = config_obj["scheme"].get<std::string>();

    LOG_INFO("Host: " + host_);
    LOG_INFO("Path: " + path_);
    LOG_INFO("Scheme: " + scheme_);
  } else {
    LOG_ERROR("Failed to get configuration");
    return false;
  }
*/
  return true;
}

//void ExampleRootContext::onTick() { LOG_TRACE("onTick"); }
//void ExampleContext::onCreate() { LOG_WARN(std::string("onCreate " + std::to_string(id()))); }

FilterHeadersStatus ExampleContext::onRequestHeaders(uint32_t, bool) {
  // LOG_INFO(std::string("onRequestHeaders ") + std::to_string(id()));
  // Store the x-verkada-auth header value
  auto auth_header = getRequestHeader("x-verkada-auth");

  // Check if request has auth header
  if (auth_header) {
    auth_key_ = auth_header->toString();

    if (auth_key_.empty()) {
      return FilterHeadersStatus::Continue;
    }
    LOG_INFO("Retrieved x-verkada-auth header: " + auth_key_);

    // Check cache
    auto* root_context = static_cast<ExampleRootContext*>(root());
    auto& cache = root_context->getCache();

    // Check if the key is in the cache
    auto cached_value = cache.Get(auth_key_.c_str());
    if (cached_value) {
      // LOG_INFO("Thread ID: " + std::to_string(std::hash<std::thread::id>{}(std::this_thread::get_id())));
      LOG_INFO("Cache hit for key: " + auth_key_ + ", cached status: " + std::to_string(*cached_value));
      //addResponseHeader(":status", std::to_string(*cached_value));
      return FilterHeadersStatus::Continue;
    } else {
      LOG_INFO("Cache miss for key: " + auth_key_);    }
  
    // Prepare headers for the POST request
    std::string body = "{}";
    /*std::vector<std::pair<std::string, std::string>> headers = {
      {":method", "POST"},
      {":path", "/auth/tokeninfo"},
  {":authority", "127.0.0.1:8081"},
  {":host", "127.0.0.1"},
      {"Content-Type", "application/json"},
      {"x-verkada-auth", auth_key_},
    };*/

    // staging2 testing
    std::vector<std::pair<std::string, std::string>> headers = {
      {":method", "POST"},
      {":path", "/auth/tokeninfo"},
      {":authority", "vauth"},
      {":host", "vauth"},
      {":scheme", "http"}, // Set the scheme to https
      {"Content-Type", "application/json"},
      {"x-verkada-auth", auth_key_},
    };

    // Make the POST request
    // Make the POST request
    auto result = root()->httpCall(
      "vauth_cluster", // Cluster name defined in Envoy configuration
      headers,
      body,
      {}, // No request trailers
      5000, // Timeout in milliseconds
      [this](uint32_t num_headers, size_t body_size, uint32_t num_trailers) {
        // Handle the response
        LOG_INFO("Received num_headers: " + std::to_string(num_headers));
        
        auto response_body = getBufferBytes(WasmBufferType::HttpCallResponseBody, 0, body_size);
        if (response_body) {
          LOG_INFO("Response body: " + response_body->toString());
        }

        // Retrieve the status code using getHeaderMapValue
    auto status_code = getHeaderMapValue(WasmHeaderMapType::HttpCallResponseHeaders, ":status");
    if (status_code) {
        LOG_INFO("status_code: " + status_code->toString());
  
    auto* root_context = static_cast<ExampleRootContext*>(root());
    auto& cache = root_context->getCache();
    cache.Insert(auth_key_, static_cast<uint16_t>(std::stoi(status_code->toString())));
    //LOG_INFO("Caching key: " + auth_key_ + ", status: " + status_code->toString());

    } else {
      LOG_ERROR("Failed to retrieve status code");
    }

      }
    );

    // Log the result of the httpCall
    if (result != WasmResult::Ok) {
      LOG_ERROR("Failed to initiate the POST request, result: " + std::to_string(static_cast<int>(result)));
    }

  }

  return FilterHeadersStatus::Continue;
}

/*FilterHeadersStatus ExampleContext::onResponseHeaders(uint32_t, bool) {
  LOG_WARN(std::string("onResponseHeaders ") + std::to_string(id()));
  
  /*
  auto result = getResponseHeaderPairs();
  auto pairs = result->pairs();
  LOG_INFO(std::string("headers: ") + std::to_string(pairs.size()));
  for (auto &p : pairs) {
    LOG_INFO(std::string(p.first) + std::string(" -> ") + std::string(p.second));
  }
  // addResponseHeader("X-Wasm-custom", "FOO");
  // replaceResponseHeader("content-type", "text/plain; charset=utf-8");
  // removeResponseHeader("content-length");

  return FilterHeadersStatus::Continue;
}*/

  FilterMetadataStatus ExampleContext::onResponseMetadata(uint32_t elements) {
    LOG_WARN(std::string("onResponseMetadata ") + std::to_string(id()) + " elements: " + std::to_string(elements));
    return FilterMetadataStatus::Continue;
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
