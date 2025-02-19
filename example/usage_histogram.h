#pragma once

/*
  This manager class is responsible for keeping track of usage histograms, locally (in WASM VM memory) and in shared data (Envoy process memory).
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <optional>
#include "proxy_wasm_api.h"
#include "proxy_wasm_intrinsics.h"

enum class TokenType {
    header_forwarded_auth,
    header_verkada_auth,
    header_verkada_auth_jwt,
    cookie_auth,
    cookie_auth_live
};

struct UsageHistogram {
    int host_id;
    int endpoint_id;
    int num_requests;
    int num_requests_header_forwarded_auth;
    int num_requests_header_verkada_auth;
    int num_requests_header_verkada_auth_jwt;
    int num_requests_cookie_auth;
    int num_requests_cookie_auth_live;
};

class UsageHistogramManager {
public:
    UsageHistogramManager() : num_total_requests(0) {}

private:

struct pair_hash {
    std::size_t operator()(const std::pair<int, int>& pair) const {
        // Use different prime numbers to combine the hashes to avoid collision
        const std::size_t prime1 = 31;
        const std::size_t prime2 = 37;
        auto hash1 = std::hash<int>{}(pair.first);
        auto hash2 = std::hash<int>{}(pair.second);
        return hash1 * prime1 + hash2 * prime2;
    }
};

    std::unordered_map<std::pair<int, int>, UsageHistogram, pair_hash> local_histograms;
    int num_total_requests;

    void updateHistogram(const UsageHistogram& input_histogram) {
        std::string key = generateKey(input_histogram.host_id, input_histogram.endpoint_id);
        WasmDataPtr value;
        uint32_t cas = 0;
        auto result = getSharedData(key, &value, &cas);

        UsageHistogram shared_histogram;
        if (result == WasmResult::Ok) {
            shared_histogram = deserialize(value->toString());
        } else {
            shared_histogram = {input_histogram.host_id, input_histogram.endpoint_id, 0, 0, 0, 0, 0, 0};
        }

        shared_histogram.num_requests += input_histogram.num_requests;
        shared_histogram.num_requests_header_forwarded_auth += input_histogram.num_requests_header_forwarded_auth;
        shared_histogram.num_requests_header_verkada_auth += input_histogram.num_requests_header_verkada_auth;
        shared_histogram.num_requests_header_verkada_auth_jwt += input_histogram.num_requests_header_verkada_auth_jwt;
        shared_histogram.num_requests_cookie_auth += input_histogram.num_requests_cookie_auth;
        shared_histogram.num_requests_cookie_auth_live += input_histogram.num_requests_cookie_auth_live;

        std::string serialized_histogram = serialize(shared_histogram);
        setSharedData(key, serialized_histogram, cas);

        // Update the shared list of <host_id, endpoint_id> pairs
        std::string list_key = "host_endpoint_list";
        WasmDataPtr list_value;
        result = getSharedData(list_key, &list_value, &cas);

        std::vector<std::pair<int, int>> host_endpoint_list;
        if (result == WasmResult::Ok) {
            host_endpoint_list = deserializeList(list_value->toString());
        }

        auto pair = std::make_pair(input_histogram.host_id, input_histogram.endpoint_id);
        if (std::find(host_endpoint_list.begin(), host_endpoint_list.end(), pair) == host_endpoint_list.end()) {
            host_endpoint_list.push_back(pair);
            std::string serialized_list = serializeList(host_endpoint_list);
            setSharedData(list_key, serialized_list, cas);
        }
    }

    void incrementHistogram(int host_id, int endpoint_id, TokenType token_type) {
        auto key = std::make_pair(host_id, endpoint_id);
        auto it = local_histograms.find(key);

        if (it == local_histograms.end()) {
            local_histograms[key] = {host_id, endpoint_id, 0, 0, 0, 0, 0, 0};
            it = local_histograms.find(key);
        }

        it->second.num_requests++;
        switch (token_type) {
            case TokenType::header_forwarded_auth:
                it->second.num_requests_header_forwarded_auth++;
                break;
            case TokenType::header_verkada_auth:
                it->second.num_requests_header_verkada_auth++;
                break;
            case TokenType::header_verkada_auth_jwt:
                it->second.num_requests_header_verkada_auth_jwt++;
                break;
            case TokenType::cookie_auth:
                it->second.num_requests_cookie_auth++;
                break;
            case TokenType::cookie_auth_live:
                it->second.num_requests_cookie_auth_live++;
                break;
        }

        num_total_requests++;
        if (num_total_requests >= 10) {
            for (const auto& pair : local_histograms) {
                updateHistogram(pair.second);
            }
            local_histograms.clear();
            num_total_requests = 0;
        }
    }

    std::string generateKey(int host_id, int endpoint_id) {
        return "hist_host_" + std::to_string(host_id) + "_endpoint_" + std::to_string(endpoint_id);
    }

    std::string serialize(const UsageHistogram& hist) {
        return std::to_string(hist.host_id) + "|" + std::to_string(hist.endpoint_id) + "|" +
               std::to_string(hist.num_requests) + "|" + std::to_string(hist.num_requests_header_forwarded_auth) + "|" +
               std::to_string(hist.num_requests_header_verkada_auth) + "|" + std::to_string(hist.num_requests_header_verkada_auth_jwt) + "|" +
               std::to_string(hist.num_requests_cookie_auth) + "|" + std::to_string(hist.num_requests_cookie_auth_live);
    }

    UsageHistogram deserialize(const std::string& data) {
        std::istringstream iss(data);
        std::string token;
        UsageHistogram hist;
        std::getline(iss, token, '|'); hist.host_id = std::stoi(token);
        std::getline(iss, token, '|'); hist.endpoint_id = std::stoi(token);
        std::getline(iss, token, '|'); hist.num_requests = std::stoi(token);
        std::getline(iss, token, '|'); hist.num_requests_header_forwarded_auth = std::stoi(token);
        std::getline(iss, token, '|'); hist.num_requests_header_verkada_auth = std::stoi(token);
        std::getline(iss, token, '|'); hist.num_requests_header_verkada_auth_jwt = std::stoi(token);
        std::getline(iss, token, '|'); hist.num_requests_cookie_auth = std::stoi(token);
        std::getline(iss, token, '|'); hist.num_requests_cookie_auth_live = std::stoi(token);
        return hist;
    }

    std::string serializeList(const std::vector<std::pair<int, int>>& list) {
        std::string result;
        for (const auto& pair : list) {
            if (!result.empty()) {
                result += ",";
            }
            result += std::to_string(pair.first) + "|" + std::to_string(pair.second);
        }
        return result;
    }

    std::vector<std::pair<int, int>> deserializeList(const std::string& data) {
        std::vector<std::pair<int, int>> list;
        std::istringstream iss(data);
        std::string token;
        while (std::getline(iss, token, ',')) {
            std::istringstream pair_iss(token);
            std::string first, second;
            std::getline(pair_iss, first, '|');
            std::getline(pair_iss, second, '|');
            list.emplace_back(std::stoi(first), std::stoi(second));
        }
        return list;
    }
};