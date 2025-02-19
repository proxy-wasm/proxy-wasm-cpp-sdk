#pragma once

#include <fnmatch.h>
#include <vector>
#include "re2/re2.h"
#include <fstream>
#include <iostream>
#include <sstream>

#include "auth_bypass_config.h"

#include "proxy_wasm_api.h"
#include "proxy_wasm_intrinsics.h"
struct Endpoint {
    std::string pattern;
    bool authenticated;
    std::unique_ptr<RE2> regex;

    // Constructor to initialize regex from pattern
    Endpoint(const std::string& pattern, bool authenticated)
        : pattern(pattern), authenticated(authenticated), regex(std::make_unique<RE2>(pattern)) {}

    // Custom copy constructor
    Endpoint(const Endpoint& other)
        : pattern(other.pattern), authenticated(other.authenticated), regex(std::make_unique<RE2>(other.pattern)) {}

    // Custom copy assignment operator
    Endpoint& operator=(const Endpoint& other) {
        if (this != &other) {
            pattern = other.pattern;
            authenticated = other.authenticated;
            regex = std::make_unique<RE2>(other.pattern);
        }
        return *this;
    }

    // Default constructor
    Endpoint() = default;

    // Move constructor and move assignment operator
    Endpoint(Endpoint&&) = default;
    Endpoint& operator=(Endpoint&&) = default;
};

struct HostConfig {
    std::string host;
    std::vector<Endpoint> endpoints;
};

class AuthConfigCheck {
public:
    AuthConfigCheck() {
        LOG_INFO("AuthConfigCheck() called");
        loadConfig();
    }

    // On match, returns a pair <host ID, endpoint ID>
    // On no match, resturns a pair <-1, -1>
    std::pair<int, int> matchRequest(const std::string& host, const std::string& path, std::string& matchType) {
        LOG_INFO("Matching request: Host = " + host + ", Path = " + path);
        for (size_t i = 0; i < hostConfigs.size(); ++i) {
            //std::cout << "Host Pattern: " << hostConfigs[i].host << std::endl;
            if (fnmatch(hostConfigs[i].host.c_str(), host.c_str(), 0) == 0) {
                LOG_INFO("Host matched: " + hostConfigs[i].host + ", Number of endpoints: " + std::to_string(hostConfigs[i].endpoints.size()));
                for (size_t j = 0; j < hostConfigs[i].endpoints.size(); ++j) {
                    const auto& endpoint = hostConfigs[i].endpoints[j];
                    LOG_INFO("Trying FullMatch.  path: " + path + ", pattern: " + endpoint.pattern);
                    if (RE2::FullMatch(path, *endpoint.regex)) {  // Using FullMatch with precompiled regex
                        matchType = endpoint.authenticated ? "authenticated" : "unauthenticated";
                        //std::cout << "Path fully matched: " << endpoint.pattern << ", Match Type: " << matchType << std::endl;
                        return {static_cast<int>(i), static_cast<int>(j)};
                    }
                }
            }
        }
        matchType = "no match";
        //std::cout << "No match found" << std::endl;
        return {-1, -1};
    }
    

private:
    std::vector<HostConfig> hostConfigs;

    void loadConfig() {
        std::istringstream file(auth_bypass_config_yaml);
    
        std::string line;
        bool inDataSection = false;
        bool inConfigYamlSection = false;
        bool inAuthCheckExceptions = false;
        bool inUnauthenticatedEndpoints = false;
        HostConfig hostConfig;

        while (std::getline(file, line)) {
            // Trim leading and trailing whitespace
            line.erase(0, line.find_first_not_of(" \t\n\r\f\v"));
            line.erase(line.find_last_not_of(" \t\n\r\f\v") + 1);
    
            if (line == "data:") {
                inDataSection = true;
                continue;
            }
    
            if (inDataSection && line == "config.yaml: |") {
                inConfigYamlSection = true;
                continue;
            }
    
            if (inConfigYamlSection && line.find("authCheckExceptions:") == 0) {
                inAuthCheckExceptions = true;
                continue;
            }
    
            if (inAuthCheckExceptions && line.find("- host:") == 0) {
                if (!hostConfig.host.empty()) {
                    hostConfigs.push_back(hostConfig);
                    hostConfig = HostConfig(); // Reset hostConfig for the next entry
                }
                std::istringstream iss(line);
                std::string dash, key, host;
                iss >> dash >> key >> host;
                hostConfig.host = host;
                // std::cout << "Found host: " << hostConfig.host << std::endl;
                LOG_INFO("Found host: " + hostConfig.host);
                inUnauthenticatedEndpoints = false; // Reset the flag for the new host
                continue;
            }
    
            if (inAuthCheckExceptions && line.find("unauthenticatedEndpoints:") == 0) {
                inUnauthenticatedEndpoints = true;
                continue;
            }
    
            if (inAuthCheckExceptions && line.find("authenticatedEndpoints:") == 0) {
                inUnauthenticatedEndpoints = false;
                continue;
            }
    
            // Try only remembering the endpoints for unauthenticatedEndpoints
            if (inUnauthenticatedEndpoints && line.find("- /") == 0) {
                std::string endpoint = line.substr(2); // Remove "- " prefix
                LOG_INFO("Found endpoint: " + endpoint + ", number: " + std::to_string(hostConfig.endpoints.size()));
                hostConfig.endpoints.emplace_back(endpoint, !inUnauthenticatedEndpoints);
                continue;
            }
    
            // End of config.yaml section
            if (inConfigYamlSection && line.empty()) {
                if (!hostConfig.host.empty()) {
                    hostConfigs.push_back(hostConfig);
                    hostConfig = HostConfig(); // Reset hostConfig for the next entry
                }
                inConfigYamlSection = false;
                inAuthCheckExceptions = false;
                inUnauthenticatedEndpoints = false;
            }
        }
    
        // Push the last hostConfig if it exists
        if (!hostConfig.host.empty()) {
            hostConfigs.push_back(hostConfig);
        }
    }
};