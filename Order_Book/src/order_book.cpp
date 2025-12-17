#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <memory>
#include <algorithm>
#include "../include/order_book.h"


/**
 * @brief calculates price of stocks when there is a requirement of a fraction of total amount.
 *
 * @param num total number of stocks to buy.
 *
 * @pre num both must be a non-negative integer less than quantity.
 *
 * @return the price of required stocks and updated the new quantity to the stock.
 *
 * @invariant All the params are const and thus invariant, only quantity changes.
 *
 * @complexity Time complexity O(1).
 */
void Order_Book::match_bid_ask() {
    double profit = 0;

    while(true) {
        if(bids.empty() || asks.empty()) break;
        std::shared_ptr<Order> bestbid = bids.begin()->second.front();
        std::shared_ptr<Order> bestask = asks.begin()->second.front();

        if(bestbid->price <= bestask->price) {
            break;
        }

        int qt = std::min(bestbid->quantity, bestask->quantity);
        profit += bestbid->buy_some(qt) - bestask->buy_some(qt);   // Here buy_some is just a method showing buy for ask and sell for bid

        if(bestask->quantity == 0) cancelOrder(bestask->Id());
        if(bestbid->quantity == 0) cancelOrder(bestbid->Id());
    }
}


/**
 * @brief calculates price of stocks when there is a requirement of a fraction of total amount.
 *
 * @param num total number of stocks to buy.
 *
 * @pre num both must be a non-negative integer less than quantity.
 *
 * @return the price of required stocks and updated the new quantity to the stock.
 *
 * @invariant All the params are const and thus invariant, only quantity changes.
 *
 * @complexity Time complexity O(1).
 */
void Order_Book::addOrder(const int& id, const int& quantity, const double& price, const std::string& side) {
    std::shared_ptr<Order> newOrder = std::make_shared<Order>(id, quantity, price, side);

    lookup_table[id] = newOrder;
    if(side[0]=='b') {
        bids[price].push_back(newOrder);
    }
    else if(side[0]=='a') {
        asks[price].push_back(newOrder);
    }

    match_bid_ask();
}


/**
 * @brief calculates price of stocks when there is a requirement of a fraction of total amount.
 *
 * @param num total number of stocks to buy.
 *
 * @pre num both must be a non-negative integer less than quantity.
 *
 * @return the price of required stocks and updated the new quantity to the stock.
 *
 * @invariant All the params are const and thus invariant, only quantity changes.
 *
 * @complexity Time complexity O(1).
 */
bool Order_Book::cancelOrder(const int& id) {
    auto it = lookup_table.find(id);
    if(it == lookup_table.end()) return false;

    std::shared_ptr<Order> stock = it->second;
    double price = stock->price;

    if(stock->Side()[0] == 'b') {
        bids[price].remove(stock);
        if(bids[price].empty()) bids.erase(price);
    }
    else if(stock->Side()[0] == 'a') {
        asks[price].remove(stock);
        if(asks[price].empty()) asks.erase(price);
    } 

    lookup_table.erase(it);
}


/**
 * @brief public instance to view the best (highest) bid
 */
const double Order_Book::getBestBid() const {
    if(bids.empty()) return -1;
    double bestbid = bids.begin()->first;
    return bestbid;
}


/**
 * @brief public instance to view the best (lowest) ask 
 */
const double Order_Book::getBestAsk() const {
    if(asks.empty()) return -1;
    double bestask = asks.begin()->first;
    return bestask;
}


/**
 * @brief public instance to view the complete order book
 */
void Order_Book::printOrderBook() const {
    std::cout << "------------ BIDS TABLE --------------" << std::endl;
    for(const auto&[price, order_list] : bids) {
        for(const auto& order : order_list) {
            std::cout << "ID: " << order->Id() << " Qt: " << order->quantity << " Price: $" << order->price << " Side: Bid" << std::endl;
        }
    }
    printf("\n\n\n\n");

    std::cout << "------------ ASKS TABLE --------------" << std::endl;
    for(const auto&[price, order_list] : asks) {
        for(const auto& order : order_list) {
            std::cout << "ID: " << order->Id() << " Qt: " << order->quantity << " Price: $" << order->price << " Side: Ask" << std::endl;
        }
    }
    printf("\n");
}


