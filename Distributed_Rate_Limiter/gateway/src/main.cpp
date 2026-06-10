#include <iostream>
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"
#include <memory>
#include <sw/redis++/redis++.h>


int main(void) {
    httplib::Server svr;

    // Initialize Redis Client Connection
    std::shared_ptr<sw::redis::Redis> redis_client;
    try {
        sw::redis::ConnectionOptions opts;
        opts.host = "redis_state";    // Map directly to redis container
        opts.port = 6379

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

    // Generic Route
    svr.Get("/(.*)", [](const httplib::Request& req, httplib::Response& res) {
        std::cout << "[Gateway Log] Intercepted Request for: " << req.path << std::endl;
        res.status = 200;
        res.set_content("{\"message\":\"Hello from the C++17 Distributed Gateway!\"}", "application/json");
    });

    std::cout << "C++ API Gateway Engine boot sequence complete. Listing to port 8000..." << std::endl;
    svr.listen("0.0.0.0", 8000);
    return 0;
}