#pragma once
#include <memory>
#include "RateLimiter.hpp"
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"


class GatewayServer {
public:
    GatewayServer(int port, std::shared_ptr<RateLimiter> limiter);
    void start();

private:
    int listen_port;
    std::shared_ptr<RateLimiter> rate_limiter;
    httplib::Server svr;
};