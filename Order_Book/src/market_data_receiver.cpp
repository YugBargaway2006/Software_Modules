#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdexcept>
#include <cstring>
#include "../include/market_data_receiver.h"
#include "../include/order.h"


/**
 * @brief creates the socket FD, binds to the port and join the multicast group.
 */
void MarketDataReceiver::init() {
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(port);

    struct ip_mreq mreq;

    sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock_fd < 0) {
        close(sock_fd);
        throw std::runtime_error("socket connection failed!");
    }

    int reuse_order = 1;
    if(setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &reuse_order, sizeof(reuse_order)) < 0) {
        close(sock_fd);
        throw std::runtime_error("socket memory address lock failed!");
    }

    if(bind(sock_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        close(sock_fd);
        throw std::runtime_error("bind to port failed!");
    }

    if(inet_aton(multicast_ip.c_str(), &mreq.imr_multiaddr) == 0) {
        close(sock_fd);
        throw std::runtime_error("multicast group address cannot setup!");
    }

    mreq.imr_interface.s_addr = htonl(INADDR_ANY);

    if(setsockopt(sock_fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char *)&mreq, sizeof(mreq)) < 0) {
        close(sock_fd);
        throw std::runtime_error("setsockopt IP_ADD_MEMBERSHIP failed!");
    }
}




