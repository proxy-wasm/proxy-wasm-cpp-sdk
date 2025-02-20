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

// For auth bypass check configuration
#include "AuthConfigCheck.h"
// For respose cache
#include "memory_cache.h"

using json = nlohmann::json;
using namespace memory_cache;

class ExampleRootContext : public RootContext {
public:
  explicit ExampleRootContext(uint32_t id, std::string_view root_id) : 
             RootContext(id, root_id), 
             total_requests_("total_requests"), 
              authConfigCheck_() {}

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

  AuthConfigCheck& getAuthConfigCheck() {
    return authConfigCheck_;
  }

  // accessors for counters
  Counter<>& getTotalRequestsCounter() {
    return total_requests_;
  }

private:
  bool config_monitor_mode_ = true; // Monitor mode by default.
  AuthConfigCheck authConfigCheck_;

  // Using Counter class to track the number of requests
  Counter<> total_requests_;
};

// Type for 128 bit integer to hold the request ID and have the same random number space with UUID.
struct uint128_t {
  uint64_t high;
  uint64_t low;

  std::string toString() const {
    char buffer[33];
    snprintf(buffer, sizeof(buffer), "%016llx%016llx", high, low);
    return std::string(buffer);
  }
};

struct RequestStatus {
  uint128_t request_id;  
  std::string uri;
  std::string token_type;
  std::string validity;
  int status_code;
  bool authenticated_endpoint;
  int endpoint_id;
  bool cached = false;
};

class ExampleContext : public Context {
public:
  explicit ExampleContext(uint32_t id, RootContext *root) : 
    Context(id, root), request_id_(generateRequestId()) {}

  //void onCreate() override;
  FilterHeadersStatus onRequestHeaders(uint32_t headers, bool end_of_stream) override;
  FilterHeadersStatus onResponseHeaders(uint32_t headers, bool end_of_stream) override;

  private:
    uint128_t request_id_; // Unique identifier for each request
    RequestStatus request_status_;
    std::string auth_key_;
    
    // Function for monitor mode
    std::string makeRequestURI();
    void logMonitor(RequestStatus& request_status);
    bool monitorOtherHeaders();

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
    // "false" in the parse function indicates that we don't want to throw an exception on parse error
    // because WASM plugin doesn't allow exceptions.
    auto config_obj = json::parse(config_json, nullptr, false);
    if (config_obj.is_discarded()) {
      LOG_ERROR("Failed to parse configuration JSON.");
    } else {
      // Check for the presence of the "monitor_mode" field
      if (config_obj.contains("monitor_mode")) {
        config_monitor_mode_ = config_obj["monitor_mode"].get<bool>();
      }
      LOG_INFO("monitor_mode: " + std::to_string(config_monitor_mode_));
    }

  }
  return true;
}

std::string ExampleContext::makeRequestURI() {
  // Retrieve the request URI components
  auto scheme_header = getRequestHeader(":scheme");
  auto host_header = getRequestHeader("Host");
  auto path_header = getRequestHeader(":path");

  std::string scheme = scheme_header ? scheme_header->toString() : "http";
  std::string host = host_header ? host_header->toString() : "unknown";
  std::string path = path_header ? path_header->toString() : "/";

  // Construct the full request URI
  std::string request_uri = scheme + "://" + host + path;

  return request_uri;
}

// Helper function to log message in monitor mode
void ExampleContext::logMonitor(RequestStatus& request_status) {
  auto* root_context = static_cast<ExampleRootContext*>(root());
  if (!root_context->isMonitorMode()) {
    return;
  }

  // Log only on this condition:
  // A request is made to an authenticated endpoint with no auth token, or an invalid one.  vShield Plugin would reject it.  But the upstream service actually allows the request.

  if (request_status.authenticated_endpoint && 
      (request_status.token_type == "absent" || request_status.validity == "invalid") && 
      (request_status.status_code >= 200 && request_status.status_code < 300)) {
        // Log the request status
        // Log format is:
        //   <request_id>
        //   <request_uri>
        //   "x-verkada-auth" "x-verkada-server-auth" "absent" <existence and type of auth token>
        //   "valid" "invalid" <validity of auth token>
        //   "response-status" <status code>
        //   "cached" "not-cached" <cache status>
        LOG_INFO("MonitorLog: " + request_status.request_id.toString() + ", " + request_status.uri + ", " + request_status.token_type + ", " + request_status.validity + 
                 ", " + std::to_string(request_status.status_code) + ", " + (request_status.cached ? "cached" : "not-cached"));
  }
}

// Returns true if any of the server headers are present
bool ExampleContext::monitorOtherHeaders() {
  auto* root_context = static_cast<ExampleRootContext*>(root());
  if (!root_context->isMonitorMode()) {
    return false;
  }
  
  request_status_.uri = makeRequestURI();
  request_status_.validity = "N/A"; // For all headers other than x-verkada-auth, we won't check validity.

  auto server_auth_jwt_header = getRequestHeader("x-verkada-server-auth-jwt");
  if (server_auth_jwt_header && !server_auth_jwt_header->toString().empty()) {
    request_status_.token_type = "x-verkada-server-auth-jwt";
    return true;
  }

  // Check for x-verkada-server-auth header
  auto server_auth_header = getRequestHeader("x-verkada-server-auth");
  if (server_auth_header && !server_auth_header->toString().empty()) {
    request_status_.token_type = "x-verkada-server-auth";
    return true;
  }

  // Check for x-verkada-forwarded-auth header
  auto forwarded_auth_header = getRequestHeader("x-verkada-forwarded-auth");
  if (forwarded_auth_header && !forwarded_auth_header->toString().empty()) {
    request_status_.token_type = "x-verkada-forwarded-auth";
    return true;
  }

  // Check for auth cookie and auth_live cookie
  auto cookie_header = getRequestHeader("Cookie");
  if (cookie_header) {
    std::string cookies = cookie_header->toString();
    if (cookies.find("auth=") != std::string::npos) {
      request_status_.token_type = "auth-cookie";
      return true;
    }
    if (cookies.find("auth_live=") != std::string::npos) {
      request_status_.token_type = "auth-live-cookie";
      return true;
    }
  }

  return false;
}

FilterHeadersStatus ExampleContext::onRequestHeaders(uint32_t, bool) {
  auto* root_context = static_cast<ExampleRootContext*>(root());

  // Add to total number of requests.
  root_context->getTotalRequestsCounter().increment(1);

  // Auth bypass check
  auto host_header = getRequestHeader("Host");
  auto path_header = getRequestHeader(":path");
  std::string host = host_header ? host_header->toString() : "unknown";
  std::string path = path_header ? path_header->toString() : "/";
  auto result = root_context->getAuthConfigCheck().matchRequest(host, path);
    LOG_INFO("Auth bypass check result for host: " + host + ", path: " + path + 
             " - HostID: " + std::to_string(std::get<0>(result)) 
             + ", EndPointID: " + std::to_string(std::get<1>(result)) + 
             ", Authenticated: " + (std::get<2>(result) ? "true" : "false"));

  request_status_.authenticated_endpoint = std::get<2>(result);
  // If the request is for an unauthenticated endpoint, skip the auth check
  // TODO: count the number of skips
  if (request_status_.authenticated_endpoint == false) {
    return FilterHeadersStatus::Continue;
  }

  // Get x-verkada-auth header value
  auto auth_header = getRequestHeader("x-verkada-auth");

  if (auth_header == nullptr || auth_header->toString().empty()) {
    // In the finished state, we should be more strict - if the call is for an authenticated endpoint,
    // and doesn't have an auth header or an auth cookie, we should terminate the request.
    // For now, we'll let the request go.
    if (!monitorOtherHeaders()) {
      request_status_.uri = makeRequestURI();
      request_status_.token_type = "absent";
      request_status_.validity = "N/A";
    }

    return FilterHeadersStatus::Continue;
  }

  // Check if request has auth header
  if (auth_header) {
    auth_key_ = auth_header->toString();

    // We have x-verkada-auth header.
    request_status_.uri = makeRequestURI();
    request_status_.token_type = "x-verkada-auth";
    request_status_.validity = "N/A";

    // Check cache
    auto& cache = root_context->getCache();

    // Check if the key is in the cache
    auto cached_value = cache.Get(auth_key_.c_str());
    if (cached_value) {
      LOG_TRACE("Cache hit for key: " + auth_key_.substr(0, 4) + ", cached status: " + std::to_string(*cached_value));
      // Cache hit means it has successful status. Continue.
      request_status_.uri = makeRequestURI();
      request_status_.token_type = "x-verkada-auth";
      request_status_.validity = "valid";
      request_status_.cached = true;
      return FilterHeadersStatus::Continue;
    }

    LOG_TRACE("Cache miss for key: " + auth_key_.substr(0, 4));
  
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
          LOG_TRACE("Response body: " + response_body->toString());
        }

        // Retrieve the status code using getHeaderMapValue
    auto status_code = getHeaderMapValue(WasmHeaderMapType::HttpCallResponseHeaders, ":status");
    if (status_code) {
        LOG_TRACE("status_code: " + status_code->toString());

        int status_code_int = std::stoi(status_code->toString());
        if (status_code_int < 200 || status_code_int > 299) {
          
          
          if (root_context->isMonitorMode()) {
            LOG_INFO("Received error status code: " + std::to_string(status_code_int) + ".  Continue the stream because of monitoring mode.");
            // In monitor mode, add a monitor log and move on
            request_status_.uri = makeRequestURI();
            request_status_.token_type = "x-verkada-auth";
            request_status_.validity = "invalid";
            continueRequest();
          } else {
            LOG_INFO("Received error status code: " + std::to_string(status_code_int) + ", terminating the stream.");
            // In non-monitor mode, send error as a local response
            sendLocalResponse(status_code_int, "Unauthorized by WASM plugin", "Unauthorized by WASM plugin", {});
            //LOG_INFO("sendLocalResponse() returned result: " + std::to_string(static_cast<int>(res)));
            // No need to call continueRequest() here because sendLocalResponse() already terminated the stream.
          }
          return; // return from the Lambda function
        }

        // vauth / vtokeninfo returned success.  token is valid.
        request_status_.uri = makeRequestURI();
        request_status_.token_type = "x-verkada-auth";
        request_status_.validity = "valid";
    // Store the status code in the cache
    auto* root_context = static_cast<ExampleRootContext*>(root());
    auto& cache = root_context->getCache();
    cache.Insert(auth_key_, static_cast<uint16_t>(std::stoi(status_code->toString())));
    continueRequest();
      } else {
      LOG_ERROR("Failed to retrieve status code from vauth / vtokeninfo");
    }

      }
    ); // closes httpCall()

    // Handle error from httpCall()
    if (call_result != WasmResult::Ok) {
      LOG_ERROR("Failed to initiate the POST request to vauth / vtokeninfo, result: " + std::to_string(static_cast<int>(call_result)));
      
      
      if (root_context->isMonitorMode()) {
        return FilterHeadersStatus::Continue;
      } else {
        // TODO: Decide fail open or fail closed.  Currently, it's fail open.
        //sendLocalResponse(500, "Failed to initiate POST request", "Failed to initiate POST request", {});
        return FilterHeadersStatus::Continue;
      }
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
  request_status_.status_code = status_code ? stoi(status_code->toString()) : 0;
  logMonitor(request_status_);
  
  return FilterHeadersStatus::Continue;
}