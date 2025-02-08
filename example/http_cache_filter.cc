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
#include <random>
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

  bool isMonitorMode() const {
    return config_monitor_mode_;
  }

private:
  bool config_monitor_mode_ = false;
};

// Type for 128 bit integer to hold the request ID and have the same random number space with UUID.
struct uint128_t {
  uint64_t high;
  uint64_t low;

  std::string toString() const {
    std::stringstream ss;
    ss << std::hex << std::setw(16) << std::setfill('0') << high
       << std::hex << std::setw(16) << std::setfill('0') << low;
    return ss.str();
  }
};

class ExampleContext : public Context {
public:
  explicit ExampleContext(uint32_t id, RootContext *root) : Context(id, root), request_id_(generateRequestId()) {}

  //void onCreate() override;
  FilterHeadersStatus onRequestHeaders(uint32_t headers, bool end_of_stream) override;
  //FilterDataStatus onRequestBody(size_t body_buffer_length, bool end_of_stream) override;
  FilterHeadersStatus onResponseHeaders(uint32_t headers, bool end_of_stream) override;
  //FilterMetadataStatus onResponseMetadata(uint32_t elements) override;
  //FilterDataStatus onResponseBody(size_t body_buffer_length, bool end_of_stream) override;
  //FilterTrailersStatus onResponseTrailers(uint32_t trailers) override;
  //void onDone() override;
  //void onLog() override;
  //void onDelete() override;
  //uint32_t getRequestId() const { return request_id_;

  private:
    uint128_t request_id_; // Unique identifier for each request
    std::string auth_key_;
    // Function for monitor mode
    void logMonitor(const std::string&, const std::string&);
    bool monitorServerHeaders();

    static uint128_t generateRequestId() {
      static std::random_device rd;
      static std::mt19937_64 gen(rd());
      static std::uniform_int_distribution<uint64_t> dis;
  
      uint128_t id;
      id.high = dis(gen);
      id.low = dis(gen);
      return id;
    }
};
static RegisterContextFactory register_ExampleContext(CONTEXT_FACTORY(ExampleContext),
                                                      ROOT_FACTORY(ExampleRootContext));

bool ExampleRootContext::onStart(size_t) {
  LOG_TRACE("onStart");
  return true;
}

bool ExampleRootContext::onConfigure(size_t configuration_size) {
  LOG_TRACE("onConfigure");
  
    // Get configuration parameters using getBufferBytes
  auto config_buffer = getBufferBytes(WasmBufferType::PluginConfiguration, 0, configuration_size);
  if (config_buffer) {
    std::string config_json = config_buffer->toString();
   LOG_TRACE("Configuration: " + config_json);

    // Parse the configuration JSON
    auto config_obj = json::parse(config_json);
    
    // Check for the presence of the "monitor_mode" field
    if (config_obj.contains("monitor_mode")) {
      config_monitor_mode_ = config_obj["monitor_mode"].get<bool>();
    } else {
      config_monitor_mode_ = false; // Set a default value if the field is not present
    }
    LOG_INFO("monitor_mode: " + std::to_string(config_monitor_mode_));
  } else {
    LOG_ERROR("Failed to get configuration");
    return false;
  }
  return true;
}

// Helper function to log message in monitor mode
void ExampleContext::logMonitor(const std::string& token_type, const std::string& validity) {
  auto* root_context = static_cast<ExampleRootContext*>(root());
  if (!root_context->isMonitorMode()) {
    return;
  }

  // Retrieve the request URI components
  auto scheme_header = getRequestHeader(":scheme");
  auto host_header = getRequestHeader("Host");
  auto path_header = getRequestHeader(":path");

  std::string scheme = scheme_header ? scheme_header->toString() : "http";
  std::string host = host_header ? host_header->toString() : "unknown";
  std::string path = path_header ? path_header->toString() : "/";

  // Construct the full request URI
  std::string request_uri = scheme + "://" + host + path;

  // Log format is:
  //   <request_id>
  //   <request_uri>
  //   "x-verkada-auth" "x-verkada-server-auth" "absent" <existence and type of auth token>
  //   "valid" "invalid" <validity of auth token>
  LOG_INFO("MonitorLog: " + request_id_.toString() + ", " + request_uri + ", " + token_type + ", " + validity);

  return;
}

// Returns true if any of the server headers are present
bool ExampleContext::monitorServerHeaders() {
  auto* root_context = static_cast<ExampleRootContext*>(root());
  if (!root_context->isMonitorMode()) {
    return false;
  }
  auto server_auth_jwt_header = getRequestHeader("x-verkada-server-auth-jwt");
  if (server_auth_jwt_header && !server_auth_jwt_header->toString().empty()) {
    logMonitor("x-verkada-server-auth-jwt", "N/A");
    return true;
  }

  // Check for x-verkada-server-auth header
  auto server_auth_header = getRequestHeader("x-verkada-server-auth");
  if (server_auth_header && !server_auth_header->toString().empty()) {
    logMonitor("x-verkada-server-auth", "N/A"); // Using -1 and false for "N/A"
    return true;
  }
  return false;
}

FilterHeadersStatus ExampleContext::onRequestHeaders(uint32_t, bool) {
  auto* root_context = static_cast<ExampleRootContext*>(root());

  LOG_TRACE(std::string("onRequestHeaders()"));

  // Store the x-verkada-auth header value
  auto auth_header = getRequestHeader("x-verkada-auth");

  // Check if request has auth header
  if (auth_header) {
    auth_key_ = auth_header->toString();

    if (auth_key_.empty()) {
      // For now, we'll let the request go if it doesn't have x-verkada-auth header.
      // In the finished state, we should be more strict - if the call is for an authenticated endpoint,
      // and doesn't have an auth header or an auth cookie, we should terminate the request.
      if (!monitorServerHeaders()) {
        logMonitor("absent", "N/A");
      }

      return FilterHeadersStatus::Continue;
    }
    LOG_TRACE("Retrieved x-verkada-auth header: " + auth_key_);

    // Check cache
    auto& cache = root_context->getCache();

    // Check if the key is in the cache
    auto cached_value = cache.Get(auth_key_.c_str());
    if (cached_value) {
      LOG_INFO("Cache hit for key: " + auth_key_ + ", cached status: " + std::to_string(*cached_value));
      // Cache hit means it has successful status. Continue.
      return FilterHeadersStatus::Continue;
    }

    LOG_INFO("Cache miss for key: " + auth_key_);
  
    // Prepare headers for the POST request to vtokeninfo / vauth
    std::string body = "{}";

      std::vector<std::pair<std::string, std::string>> headers = {
      {":method", "POST"},
      {":path", "/auth/tokeninfo"},
      {":authority", "vauth"},
      {":host", "vauth"},
      {":scheme", "http"}, // Set the scheme to https
      {"Content-Type", "application/json"},
      {"x-verkada-auth", auth_key_},
    };

    // Capture the ID of the current Context (representing the current request)
    uint32_t context_id = id();

    // Make the POST request
    auto call_result = root()->httpCall(
      "vauth_cluster", // Cluster name defined in Envoy configuration
      headers,
      body,
      {}, // No request trailers
      5000, // Timeout in milliseconds
      [this, context_id, root_context](uint32_t num_headers, size_t body_size, uint32_t num_trailers) {
        // Switch to the correct context using proxy_set_effective_context
        // httpCall() is run inside the root context.  But we can't send local response from the root context.
        // Therefore, we need to switch to the context of the request.
        proxy_set_effective_context(context_id);

        // Handle the response
        auto response_body = getBufferBytes(WasmBufferType::HttpCallResponseBody, 0, body_size);
        if (response_body) {
          LOG_INFO("Response body: " + response_body->toString());
        }

        // Retrieve the status code using getHeaderMapValue
    auto status_code = getHeaderMapValue(WasmHeaderMapType::HttpCallResponseHeaders, ":status");
    if (status_code) {
        LOG_INFO("status_code: " + status_code->toString());

        int status_code_int = std::stoi(status_code->toString());
        if (status_code_int < 200 || status_code_int > 299) {
          LOG_INFO("Received error status code: " + std::to_string(status_code_int) + ", terminating the stream");

          
          if (root_context->isMonitorMode()) {
            // In monitor mode, add a monitor log and move on
            logMonitor("x-verkada-auth", "invalid");
            continueRequest();
          } else {
            // In non-monitor mode, send error as a local response
            sendLocalResponse(status_code_int, "Unauthorized by WASM plugin", "Unauthorized by WASM plugin", {});
            //LOG_INFO("sendLocalResponse() returned result: " + std::to_string(static_cast<int>(res)));
            continueRequest();
          //LOG_INFO("closeRequest() returned result: " + std::to_string(static_cast<int>(res)));
          }
          return; // return from the Lambda function
        }

        logMonitor("x-verkada-auth", "valid");
    // Store the status code in the cache
    auto* root_context = static_cast<ExampleRootContext*>(root());
    auto& cache = root_context->getCache();
    cache.Insert(auth_key_, static_cast<uint16_t>(std::stoi(status_code->toString())));
    continueRequest();
      } else {
      LOG_ERROR("Failed to retrieve status code");
    }

      }
    ); // closes httpCall()

    // Handle error from httpCall()
    if (call_result != WasmResult::Ok) {
      LOG_ERROR("Failed to initiate the POST request, result: " + std::to_string(static_cast<int>(call_result)));
      sendLocalResponse(500, "Failed to initiate POST request", "Failed to initiate POST request", {});
      return FilterHeadersStatus::ContinueAndEndStream;
    }

    // fall through to the end of this function
  }  // if (auth_header)
  else {
    LOG_TRACE("No x-verkada-auth header found");
  }

  // Return stop iteration because we are waiting for the response from the external auth server.
  LOG_TRACE("Waiting for response from external auth server");
  //return FilterHeadersStatus::StopAllIterationAndWatermark;
  return FilterHeadersStatus::StopIteration;
}

FilterHeadersStatus ExampleContext::onResponseHeaders(uint32_t headers, bool end_of_stream) {
  LOG_TRACE("onResponseHeaders()");
  
  auto status_code = getResponseHeader(":status");
  std::string status = status_code ? status_code->toString() : "unknown";
  logMonitor("response-status", status);
  
  return FilterHeadersStatus::Continue;
}