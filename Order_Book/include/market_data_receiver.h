#pragma once

#include <string>
#include <unistd.h>


class MarketDataReceiver {
private:
    std::string multicast_ip;
    int port;
    int sock_fd;

public:
    MarketDataReceiver(const std::string& ip, const int& port)
    : multicast_ip(ip)
    , port(port)
    {}

    ~MarketDataReceiver() {
        if(sock_fd > 0) close(sock_fd);
    }

    void init();

    
};