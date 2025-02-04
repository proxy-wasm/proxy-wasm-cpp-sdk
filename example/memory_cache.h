#pragma once

#include <unordered_map>
#include <mutex>
#include <optional>
#include <cstdint> // For uint16_t
#include <cstring> // For strcmp
#include <iostream> // For debug output
#include <chrono> // For std::chrono

namespace memory_cache {

struct CacheItem {
        uint16_t value;
        std::chrono::steady_clock::time_point expiration_time;
    };

/**
  A simple in-memory cache class with TTL.
  It restricts stored values to 16-bit unsigned integers. This also makes it memory efficient.
 */
class MemoryCache {
public:
    // By default, TTL will be 86400 seconds (1 day).
    MemoryCache(std::size_t max_size, int default_ttl_seconds = 86400)
        : max_cache_size(max_size), default_ttl_seconds(default_ttl_seconds) {

          // Perf test
          /*
          for (int i = 0; i < max_size; ++i) {
            std::string key = generateKey(i);
            //std::cout << "Inserting key: " << key << std::endl;
            //CacheItem item = {static_cast<uint16_t>(200), std::chrono::steady_clock::now() + std::chrono::seconds(default_ttl_seconds)};
            Insert(key, 200, -1); // Assuming MemoryCache has an insert method
        }*/

        //LOG_INFO("Inserted 1 million objects into the cache");

        }

std::string serialize(const CacheItem& item) {
    // Example: value|expiration_time
    return std::to_string(item.value) + "|" + std::to_string(item.expiration_time.time_since_epoch().count());
}

CacheItem deserialize(const std::string_view& data) {
    // Example: value|expiration_time
    size_t delimiter_pos = data.find('|');
    uint16_t value = std::stoi(std::string(data.substr(0, delimiter_pos)));
    auto expiration_time = std::chrono::steady_clock::time_point(std::chrono::steady_clock::duration(std::stoll(std::string(data.substr(delimiter_pos + 1)))));
    return {value, expiration_time};
}

    bool Insert(const std::string& key, uint16_t value, int ttl_seconds = -1) {
        // Check if the key is empty
    if (key.empty()) {
        LOG_ERROR("memory_cache::Insert() Key is empty");
      return false;
    }

        
        if (ttl_seconds == -1) {
            ttl_seconds = default_ttl_seconds;
        }

        static uint64_t insert_call_count = 0;
        static uint64_t cumulative_time_microseconds = 0;
        auto start_time = std::chrono::steady_clock::now();
        // TODO: Add 5% jitter to TTL
/*        std::uniform_real_distribution<double> distribution(-0.05, 0.05);
        double jitter_factor = distribution(random_generator);
        auto jittered_ttl = std::chrono::seconds(ttl_seconds) +
                        std::chrono::seconds(static_cast<int>(ttl_seconds * jitter_factor));
         auto expiration_time = time_source_.monotonicTime() + jittered_ttl;
*/
        auto expiration_time = std::chrono::steady_clock::now() + std::chrono::seconds(ttl_seconds);
        //std::lock_guard<std::mutex> lock(safe_op);

        CacheItem item = {value, expiration_time};
        
        // TODO: implement eviction
        /*auto it = cache_items_map.find(key.c_str());
        if (it == cache_items_map.end()) {
            if (cache_items_map.size() >= max_cache_size) {
                Evict();
            }
            cache_items_map[key.c_str()] = item;
        } else {
            cache_items_map[key.c_str()] = item;
        }
        return true;*/

    std::string serialized_item = serialize(item);
    uint32_t cas = 0;

    // Get the current value and CAS
    //WasmDataPtr current_value;
    uint32_t current_cas;


    //auto get_result = getSharedData(key, nullptr, &current_cas);
    /*if (get_result != WasmResult::Ok) {
      std::cerr << "Failed to get shared data for key: " << key << std::endl;
      std::exit(EXIT_FAILURE);
    }*/

    

    // Set the new value with CAS
    /*auto set_result = setSharedData(key, serialized_item, current_cas);
    if (set_result != WasmResult::Ok) {
      std::cerr << "CAS failure for key: " << key << std::endl;
      //std::exit(EXIT_FAILURE); // Terminate the process
    } else {
        LOG_INFO("Inserted key: " + key
    }*/
    auto result = setSharedData(key, serialized_item, cas);

    auto end_time = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

    cumulative_time_microseconds += duration;
    insert_call_count++;

    if (insert_call_count % 100 == 0) {
        LOG_ERROR("Total Insert calls: " + std::to_string(insert_call_count));
        LOG_ERROR("Cumulative time (microseconds): " + std::to_string(cumulative_time_microseconds));
        LOG_ERROR("Average time per Insert call (microseconds): " + std::to_string(cumulative_time_microseconds / insert_call_count));
    }

    return true;
    }

    bool Erase(const std::string &key) {
        //std::lock_guard<std::mutex> lock(safe_op);
        auto it = cache_items_map.find(key.c_str());
        if (it != cache_items_map.end()) {
            //free(const_cast<char*>(it->first));
            cache_items_map.erase(it);
            return true;
        }
        return false;
    }

    std::optional<uint16_t> Get(const std::string &key) {
        static uint64_t get_call_count = 0;
        static uint64_t cumulative_time_microseconds = 0;
        //std::lock_guard<std::mutex> lock(safe_op);

        auto start_time = std::chrono::steady_clock::now();

        uint32_t cas = 0;
        WasmDataPtr value;
        auto result = getSharedData(key, &value, &cas);
    if (result == WasmResult::Ok) {
        CacheItem item = deserialize(value->toString());
        if (std::chrono::steady_clock::now() < item.expiration_time) {

            auto end_time = std::chrono::steady_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

            cumulative_time_microseconds += duration;
            get_call_count++;

            if (get_call_count % 10000 == 0) {
              LOG_ERROR("Total Get calls: " + std::to_string(get_call_count));
              LOG_ERROR("Cumulative time (microseconds): " + std::to_string(cumulative_time_microseconds));
              LOG_ERROR("Average time per Get call (microseconds): " + std::to_string(cumulative_time_microseconds / get_call_count));
            }

            return item.value;
        } else {
            //std::cout << "Item " << key << " has expired" << std::endl;
            // Item has expired
            Erase(key);
        }
    } else {
        //std::cout << "Key not found: " << key << std::endl;
    }

        return std::nullopt;
    }

    size_t Size() const {
        //std::lock_guard<std::mutex> lock(safe_op);
        return cache_items_map.size();
    }

    ~MemoryCache() {
        for (auto& pair : cache_items_map) {
            free(const_cast<char*>(pair.first));
        }
    }

private:
    std::string generateKey(int counter) {
        char buffer[36];
        snprintf(buffer, sizeof(buffer), "v2_%032x", counter);
        return std::string(buffer);
    }

    void Evict() {
        // TODO: implement more sophisticated eviction policy
        if (!cache_items_map.empty()) {
            auto it = cache_items_map.begin();
            free(const_cast<char*>(it->first));
            cache_items_map.erase(it);
        }
    }

    struct CharPtrHash {
        std::size_t operator()(const char* str) const {
            std::size_t hash = 0;
            while (*str) {
                hash = hash * 101 + *str++;
            }
            return hash;
        }
    };

    struct CharPtrEqual {
        bool operator()(const char* lhs, const char* rhs) const {
            return std::strcmp(lhs, rhs) == 0;
        }
    };

    std::unordered_map<const char*, CacheItem, CharPtrHash, CharPtrEqual> cache_items_map;
    std::size_t max_cache_size;
    int default_ttl_seconds;
    //mutable std::mutex safe_op;
};

} // namespace memory_cache