#include "ConfigManager.hpp"
#include <iostream>
#include <nlohmann/json.hpp>

#define THREADED

#include <zookeeper/zookeeper.h>


using json = nlohmann::json;

// Static atomics allocated in the header
std::atomic<int> ConfigManager::rate_capacity{5};
std::atomic<int> ConfigManager::rate_refill{1};
std::atomic<int> ConfigManager::window_size{60};
std::atomic<int> ConfigManager::active_algorithm{0};

ConfigManager::ConfigManager(const std::string& zk_host) {
    zk_client = zookeeper_init(zk_host.c_str(), global_watcher, 10000, 0, this, 0);
    if (!zk_client) {
        std::cerr << "Failed to initialize Zookeeper client." << std::endl;
    }
}

int ConfigManager::get_capacity() const { return rate_capacity.load(); }
int ConfigManager::get_refill_rate() const { return rate_refill.load(); }
int ConfigManager::get_window_size() const { return window_size.load(); }
int ConfigManager::get_algorithm() const { return active_algorithm.load(); }

void ConfigManager::fetch_config(zhandle_t *zh) {
    char buffer[1024];
    int buffer_len = sizeof(buffer);
    
    int rc = zoo_wget(zh, "/rate_limiter/config", config_watcher, nullptr, buffer, &buffer_len, nullptr);
    
    if (rc == ZOK && buffer_len > 0) {
        try {
            auto j = json::parse(std::string(buffer, buffer_len));
            
            if (j.contains("capacity")) rate_capacity.store(j["capacity"]);
            if (j.contains("refill_rate")) rate_refill.store(j["refill_rate"]);
            if (j.contains("window_size")) window_size.store(j["window_size"]);
            
            if (j.contains("algorithm")) {
                std::string algo = j["algorithm"];
                if (algo == "fixed_window") active_algorithm.store(1);
                else if (algo == "sliding_window") active_algorithm.store(2);
                else active_algorithm.store(0); // Default Token Bucket
            }
            
            std::cout << "[ConfigManager] ZK Rules Updated -> Algo: " << active_algorithm.load() 
                      << " | Cap: " << rate_capacity.load() << " | Window: " << window_size.load() << "s" << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "ZK JSON Parse Error: " << e.what() << std::endl;
        }
    } else if (rc == ZNONODE) {
        zoo_wexists(zh, "/rate_limiter/config", config_watcher, nullptr, nullptr);
    }
}

void ConfigManager::config_watcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx) {
    if (type == ZOO_CHANGED_EVENT || type == ZOO_CREATED_EVENT) fetch_config(zh);
}

void ConfigManager::global_watcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx) {
    if (type == ZOO_SESSION_EVENT && state == ZOO_CONNECTED_STATE) {
        std::cout << "Connected to ZooKeeper Consensus Cluster!" << std::endl;
        fetch_config(zh);
    }
}