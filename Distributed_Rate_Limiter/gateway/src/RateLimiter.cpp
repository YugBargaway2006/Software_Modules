#include "RateLimiter.hpp"
#include <iostream>
#include <chrono>
#include <random>


RateLimiter::RateLimiter(const std::string& redis_host, std::shared_ptr<ConfigManager> config)
    : current_config(config),
      token_bucket_script(R"(
        local key = KEYS[1]
        local capacity = tonumber(ARGV[1])
        local refill_rate = tonumber(ARGV[2])
        local now = tonumber(ARGV[3])
        local requested = tonumber(ARGV[4])
        local data = redis.call('HMGET', key, 'tokens', 'last_updated')
        local tokens = tonumber(data[1])
        local last_updated = tonumber(data[2])
        if not tokens then
            tokens = capacity
            last_updated = now
        else
            local elapsed = now - last_updated
            if elapsed > 0 then
                tokens = math.min(capacity, tokens + (elapsed * refill_rate))
                last_updated = now
            end
        end
        if tokens >= requested then
            tokens = tokens - requested
            redis.call('HMSET', key, 'tokens', tokens, 'last_updated', last_updated)
            return 1
        else
            redis.call('HMSET', key, 'tokens', tokens, 'last_updated', last_updated)
            return 0
        end
      )"),

      fixed_window_script(R"(
        local key = KEYS[1]
        local limit = tonumber(ARGV[1])
        local window = tonumber(ARGV[2])
        local current = redis.call('GET', key)
        if current and tonumber(current) >= limit then
            return 0
        end
        current = redis.call('INCR', key)
        if tonumber(current) == 1 then
            redis.call('EXPIRE', key, window)
        end
        return 1
      )"),

      sliding_window_script(R"(
        local key = KEYS[1]
        local limit = tonumber(ARGV[1])
        local window = tonumber(ARGV[2])
        local now = tonumber(ARGV[3])
        local unique_id = ARGV[4]
        local window_start = now - window
        redis.call('ZREMRANGEBYSCORE', key, '-inf', window_start)
        local current_requests = redis.call('ZCARD', key)
        if current_requests >= limit then
            return 0
        end
        redis.call('ZADD', key, now, now .. '-' .. unique_id)
        redis.call('EXPIRE', key, window)
        return 1
      )") 
{
    try {
        sw::redis::ConnectionOptions opts;
        opts.host = redis_host;
        opts.port = 6379;
        sw::redis::ConnectionPoolOptions pool_opts;
        pool_opts.size = 10;
        redis_client = std::make_shared<sw::redis::Redis>(opts, pool_opts);
        std::cout << "Redis Pool initialized successfully" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Redis Client Error: " << e.what() << std::endl;
    }
}


bool RateLimiter::is_request_allowed(const std::string& client_ip) {
    if (!redis_client) return false; // Fail safe

    std::string redis_key = "rate_limit:" + client_ip;
    int algo = current_config->get_algorithm();
    std::string capacity = std::to_string(current_config->get_capacity());
    long long result = 0;

    auto now_seconds = std::to_string(std::chrono::duration_cast<std::chrono::seconds>(
        std::chrono::system_clock::now().time_since_epoch()).count());

    try {
        if (algo == 0) { // Token Bucket
            std::string refill = std::to_string(current_config->get_refill_rate());
            result = redis_client->eval<long long>(token_bucket_script, {redis_key}, {capacity, refill, now_seconds, "1"});
        } else if (algo == 1) { // Fixed Window
            std::string window = std::to_string(current_config->get_window_size());
            result = redis_client->eval<long long>(fixed_window_script, {redis_key}, {capacity, window});
        } else if (algo == 2) { // Sliding Window
            std::string window = std::to_string(current_config->get_window_size());
            static std::random_device rd;
            static std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib(1, 100000);
            std::string unique_req_id = std::to_string(distrib(gen)); 
            result = redis_client->eval<long long>(sliding_window_script, {redis_key}, {capacity, window, now_seconds, unique_req_id});
        }
        return result == 1;
    } catch (const std::exception& e) {
        std::cerr << "Redis Client Execution Error: " << e.what() << std::endl;
        return false;
    }
}