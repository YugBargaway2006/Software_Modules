#include <iostream>
#include <memory>
#include <string>
#include <chrono>
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"
#include <sw/redis++/redis++.h>


// Atomic Token Bucket Script in Lua
const std::string LUA_TOKEN_BUCKET = R"(
    local key = KEYS[1]
    local capacity = tonumber(ARGV[1])
    local refill_rate = tonumber(ARGV[2])
    local now = tonumber(ARGV[3])
    local requested = tonumber(ARGV[4])

    -- Fetch current bucket state
    local data = redis.call('HMGET', key, 'tokens', 'last_updated')
    local tokens = tonumber(data[1])
    local last_updated = tonumber(data[2])

    -- Initialize bucket if user dne
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

    -- Rate Limiter Logic
    if tokens >= requested then
        tokens = tokens - requested 
        redis.call('HMSET', key, 'tokens', tokens, 'last_updated', last_updated)
        return 1    -- Allowed
    else 
        redis.call('HMSET', key, 'tokens', tokens, 'last_updated', last_updated)
        return 0    -- Throtted (HTTP 429)
    end
)";


int main(void) {
    httplib::Server svr;

    // Initialize Redis Client Connection
    std::shared_ptr<sw::redis::Redis> redis_client;
    try {
        sw::redis::ConnectionOptions opts;
        opts.host = "redis_state";    // Map directly to redis container
        opts.port = 6379;

        sw::redis::ConnectionPoolOptions pool_opts;
        pool_opts.size = 10;    // Max active connections in gateway pool

        redis_client = std::make_shared<sw::redis::Redis>(opts, pool_opts);
        std::cout << "Redis Pool initialized successfully" << std::endl;
    } 
    catch(const std::exception& e) {
        std::cerr << "Error initializing Redis connection: " << e.what() << std::endl;
        return 1;
    }

    // Health Check Route
    svr.Get("/health", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("{\"status\":\"healthy\", \"engine\":\"C++17\"}", "application/json");
    });

    // Verification Route to test Redis Cache
    svr.Get("/redis-ping", [redis_client](const httplib::Request&, httplib::Response& res) {
        try {
            // Send a ping command
            std::string pong = redis_client->ping();
            res.status = 200;
            res.set_content("{\"redis_status\":\"connected\",\"response\":\"" + pong + "\"}", "application/json");
        }
        catch (const sw::redis::Error& e) {
            res.status = 500;
            res.set_content("{\"redis_status\":\"disconnected\",\"error\":\"" + std::string(e.what()) + "\"}", "application/json");
        }
    });

    // Core Gateway Route
    svr.Get("/(.*)", [redis_client](const httplib::Request& req, httplib::Response& res) {
        std::string client_ip = req.remote_addr;
        // Extract forwarded IP from the HAProxy packet
        if(req.has_header("X-Forwarded-For")) {
            client_ip = req.get_header_value("X-Forwarded-For");
        }

        std::string redis_key = "rate_limit: " + client_ip;

        // Rate Limiting Rules
        std::string capacity = "5";
        std::string refill_rate = "1";

        auto now_seconds = std::to_string(std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::system_clock::now().time_since_epoch()).count());
            
        std::string requested = "1";

        try {
            // Run lua script on redis server
            // KEYS[1] = redis_key
            // ARGV = {capacity, refill_rate, now_seconds, requested}
            auto result = redis_client->eval<long long>(
                LUA_TOKEN_BUCKET,
                {redis_key},
                {capacity, refill_rate, now_seconds, requested}
            );

            if (result == 1) {
                // Reverse proxy forwarding logic
                httplib::Client cli("backend-services", 5000);

                if(auto backend_res = cli.Get(req.path)) {
                    res.status = backend_res->status;
                    res.set_header("X-Backend-Server", "C++ Gateway Proxy Node");
                    res.set_content(backend_res->body, backend_res->get_header_value("Content-Type"));
                } else {
                    res.status = 502;    // Bad Gateway
                    res.set_content("{\"error\":\"Bad Gateway\",\"message\":\"Failed to communicate with internal microservices.\"}", "application/json");
                }
            } else {
                res.status = 429;      // Too Many Requests
                res.set_content("{\"error\":\"Too Many Requests\",\"message\":\"Rate limit exceeded. Bucket empty.\"}\n", "application/json");
            }
        }
        catch (const std::exception& e) {
            res.status = 500;
            res.set_content("{\"error\":\"Internal Server Error\",\"details\":\"" + std::string(e.what()) + "\"}", "application/json\n");
        }

        // std::cout << "[Gateway Log] Intercepted Request for: " << req.path << std::endl;
        // res.status = 200;
        // res.set_content("{\"message\":\"Hello from the C++17 Distributed Gateway!\"}", "application/json");
    });

    std::cout << "C++ API Gateway Engine boot sequence complete. Listing to port 8000..." << std::endl;
    svr.listen("0.0.0.0", 8000);
    return 0;
}