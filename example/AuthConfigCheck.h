#pragma once

#include <fnmatch.h>
#include <vector>
#include "re2/re2.h"
#include <yaml-cpp/yaml.h>
#include <iostream>

struct Endpoint {
    std::string pattern;
    bool authenticated;
};

struct HostConfig {
    std::string host;
    std::vector<Endpoint> endpoints;
};

class AuthConfigCheck {
public:
    AuthConfigCheck(const std::string& yamlFilePath) {
        loadConfig(yamlFilePath);
    }

    std::pair<int, int> matchRequest(const std::string& host, const std::string& path, std::string& matchType) {
        std::cout << "Matching request: Host = " << host << ", Path = " << path << std::endl;
        for (size_t i = 0; i < hostConfigs.size(); ++i) {
            std::cout << "Host Pattern: " << hostConfigs[i].host << std::endl;
            if (fnmatch(hostConfigs[i].host.c_str(), host.c_str(), 0) == 0) {
                std::cout << "Host matched: " << hostConfigs[i].host << std::endl;
                for (size_t j = 0; j < hostConfigs[i].endpoints.size(); ++j) {
                    const std::string& pattern = hostConfigs[i].endpoints[j].pattern;
                    if (RE2::FullMatch(path, pattern)) {
                        matchType = hostConfigs[i].endpoints[j].authenticated ? "authenticated" : "unauthenticated";
                        std::cout << "Path matched: " << pattern << ", Match Type: " << matchType << std::endl;
                        return {static_cast<int>(i), static_cast<int>(j)};
                    }
                }
            }
        }
        matchType = "no match";
        std::cout << "No match found" << std::endl;
        return {-1, -1};
    }

private:
    std::vector<HostConfig> hostConfigs;

    void loadConfig(const std::string& yamlFilePath) {
        std::vector<YAML::Node> configs = YAML::LoadAllFromFile(yamlFilePath);
        std::cout << "Loaded YAML config: " << std::endl;

        for (const auto& config : configs) {
            if (!config["data"]) {
                std::cout << "Invalid YAML structure: 'data' not found" << std::endl;
                throw std::runtime_error("Invalid YAML structure: 'data' not found");
            }
            if (!config["data"]["config.yaml"]) {
                std::cout << "Invalid YAML structure: 'config.yaml' not found" << std::endl;
                throw std::runtime_error("Invalid YAML structure: 'config.yaml' not found");
            }
            std::cout << "config.yaml: " << config["data"]["config.yaml"] << std::endl;

            // Parse the nested YAML string
            YAML::Node nestedConfig = YAML::Load(config["data"]["config.yaml"].as<std::string>());
            if (!nestedConfig["authCheckExceptions"]) {
                std::cout << "Invalid YAML structure: 'authCheckExceptions' not found" << std::endl;
                throw std::runtime_error("Invalid YAML structure: 'authCheckExceptions' not found");
            }

            YAML::Node authCheckExceptions = nestedConfig["authCheckExceptions"];

            for (size_t i = 0; i < authCheckExceptions.size(); ++i) {
                HostConfig hostConfig;
                if (!authCheckExceptions[i]["host"]) {
                    throw std::runtime_error("Invalid YAML structure: 'host' not found in authCheckExceptions");
                }
                hostConfig.host = authCheckExceptions[i]["host"].as<std::string>();
                std::cout << "Loaded host: " << hostConfig.host << std::endl;

                if (authCheckExceptions[i]["authenticatedEndpoints"]) {
                    for (const auto& endpoint : authCheckExceptions[i]["authenticatedEndpoints"]) {
                        hostConfig.endpoints.push_back({endpoint.as<std::string>(), true});
                        std::cout << "Loaded authenticated endpoint: " << endpoint.as<std::string>() << std::endl;
                    }
                }

                if (authCheckExceptions[i]["unauthenticatedEndpoints"]) {
                    for (const auto& endpoint : authCheckExceptions[i]["unauthenticatedEndpoints"]) {
                        hostConfig.endpoints.push_back({endpoint.as<std::string>(), false});
                        std::cout << "Loaded unauthenticated endpoint: " << endpoint.as<std::string>() << std::endl;
                    }
                }

                hostConfigs.push_back(hostConfig);
            }
        }
    }
};