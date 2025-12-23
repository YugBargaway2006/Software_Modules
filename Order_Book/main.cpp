#include <iostream>
#include <csignal>
#include "include/order_book.h"
#include "include/order.h"
#include "include/market_data_receiver.h"

int main() {
    std::signal(SIGINT, signal_handler);
    // raise(SIGINT);

    Order_Book book;

    MarketDataReceiver receiver("239.0.0.1", 8080);
    try {
        receiver.init();
        receiver.start(book);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    std::cout << "\n--- FLUSHING TRADE BOOK ---\n";
    book.flushlog();    

    return 0;
}