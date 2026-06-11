#pragma once
#include <string>
#include <atomic>

#define THREADED
#include <zookeeper/zookeeper.h>



class ConfigManager {
public:
    ConfigManager(const std::string& zk_host);
    
    // Thread-safe getters
    int get_capacity() const;
    int get_refill_rate() const;
    int get_window_size() const;
    int get_algorithm() const;

private:
    zhandle_t* zk_client;
    // Global atomics 
    static std::atomic<int> rate_capacity;
    static std::atomic<int> rate_refill;
    static std::atomic<int> window_size;
    static std::atomic<int> active_algorithm;

    static void global_watcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx);
    static void config_watcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx);
    static void fetch_config(zhandle_t *zh);
};