#include <iostream>
#include <memory>
#include "ConfigManager.hpp"
#include "RateLimiter.hpp"
#include "GatewayServer.hpp"

int main() {
    std::cout << "🚀 Booting Distributed API Gateway..." << std::endl;

    // ZooKeeper System
    auto config = std::make_shared<ConfigManager>("zookeeper:2181");

    // Redis Execution Engine
    auto limiter = std::make_shared<RateLimiter>("redis_state", config);

    // HTTP Server
    GatewayServer server(8000, limiter);
    server.start();

    return 0;
}