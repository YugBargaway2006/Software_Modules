#include <iostream>
#include "include/order_book.h"
#include "include/order.h"
#include "include/market_data_receiver.h"

int main() {
    Order_Book book;

    MarketDataReceiver receiver("239.0.0.1", 8080);
    receiver.start(book);


    // std::cout << "--- 1. ADD BUY 100 @ 100 (ID 1) ---\n";
    // book.addOrder(1, 100, 100.0, Side::bid);
    // book.printOrderBook();

    // std::cout << "--- 2: ADD BUY 50 @ 101 (ID 2) ---\n";
    // book.addOrder(2, 50, 101.0, Side::bid);
    // book.printOrderBook();

    // std::cout << "--- 3: ADD SELL 100 @ 102 (ID 3) ---\n";
    // book.addOrder(3, 100, 102.0, Side::ask);
    // book.printOrderBook();

    // std::cout << "--- 4: ADD SELL 100 @ 100 (ID 4) ---\n";
    // book.addOrder(4, 100, 100.0, Side::ask);
    
    // std::cout << "\n--- FINAL BOOK STATE ---\n";
    // book.printOrderBook();

    return 0;
}