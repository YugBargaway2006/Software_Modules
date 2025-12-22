#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <vector>
#include "include/protocol.h"


/**
 * @brief Entrypoint for the market data publisher.
 */
int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");    // Multicast Group
    addr.sin_port = htons(8080); // Port

    struct in_addr localInterface;
    localInterface.s_addr = inet_addr("127.0.0.1"); // FORCE LOCALHOST
    if (setsockopt(sock, IPPROTO_IP, IP_MULTICAST_IF, (char *)&localInterface, sizeof(localInterface)) < 0) {
        perror("Setting local interface error");
        exit(1);
    }

    char loop = 1;
    if(setsockopt(sock, IPPROTO_IP, IP_MULTICAST_LOOP, &loop, sizeof(loop)) < 0) {
        perror("Setting IP_MULTICAST_LOOP error");
    }

    std::cout << "Starting Market Simulator...\n";

    int order_id = 1;
    while (true) {
        OrderMessage msg;   // Create Order
        msg.header.msgLength = sizeof(OrderMessage);
        msg.header.msgType = 1;    // Add Order
        
        // Network Byte Order!
        msg.orderID = htonl(order_id++);
        msg.price = htonl(10000 + (rand() % 500)); // 100.00 to 105.00
        msg.quantity = htonl(10 + (rand() % 100));
        msg.side = (rand() % 2 == 0) ? 'B' : 'S';

        sendto(sock, &msg, sizeof(msg), 0, (struct sockaddr*)&addr, sizeof(addr));

        // Throttle (10 orders per second)
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        
        if (order_id % 10 == 0) std::cout << "Sent " << order_id << " orders\n";
    }
    return 0;
}