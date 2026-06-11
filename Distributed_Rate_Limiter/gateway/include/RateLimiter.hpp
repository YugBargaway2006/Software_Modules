#pragma once
#include <string>
#include <memory>
#include <sw/redis++/redis++.h>
#include "ConfigManager.hpp"


class RateLimiter {
public:
    RateLimiter(const std::string& redis_host, std::shared_ptr<ConfigManager> config);
    
    // Returns true if the request is allowed, false if it should be blocked (429)
    bool is_request_allowed(const std::string& client_ip);

private:
    std::shared_ptr<sw::redis::Redis> redis_client;
    std::shared_ptr<ConfigManager> current_config;
    
    // Lua Script
    const std::string token_bucket_script;
    const std::string fixed_window_script;
    const std::string sliding_window_script;
};