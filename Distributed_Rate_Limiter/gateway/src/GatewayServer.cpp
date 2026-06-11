#include "GatewayServer.hpp"
#include <iostream>


GatewayServer::GatewayServer(int port, std::shared_ptr<RateLimiter> limiter) 
    : listen_port(port), rate_limiter(limiter) {
    
    svr.Get("/(.*)", [this](const httplib::Request& req, httplib::Response& res) {
        std::string client_ip = req.remote_addr;
        if (req.has_header("X-Forwarded-For")) {
            client_ip = req.get_header_value("X-Forwarded-For");
        }

        // Passes the IP to the execution part
        if (rate_limiter->is_request_allowed(client_ip)) {
            httplib::Client cli("backend-services", 5000);
            if (auto backend_res = cli.Get(req.path)) {
                res.status = backend_res->status;
                res.set_header("X-Backend-Server", "C++ Engine Node");
                res.set_content(backend_res->body, backend_res->get_header_value("Content-Type"));
            } else {
                res.status = 502;
                res.set_content("{\"error\":\"Bad Gateway\"}", "application/json");
            }
        } else {
            res.status = 429;
            res.set_content("{\"error\":\"Too Many Requests\"}", "application/json");
        }
    });
}

void GatewayServer::start() {
    std::cout << "Gateway Booted. Listening on port " << listen_port << "..." << std::endl;
    svr.listen("0.0.0.0", listen_port);
}