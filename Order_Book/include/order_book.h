#pragma once

#include <map>
#include <list>
#include <string>
#include <memory>
#include <unordered_map>
#include "order.h"


class Order_Book {
private:
    std::map<double, std::list<std::shared_ptr<Order>>, std::greater<double>> bids;   // Take the highest Bid First
    std::map<double, std::list<std::shared_ptr<Order>>, std::less<double>> asks;      // Take the lowest ask first
    std::unordered_map<int, std::shared_ptr<Order>> lookup_table;

    void match_bid_ask();

public:
    Order_Book() {}

    void addOrder(const int& id, const int& quantity, const double& price, const std::string& side);
    bool cancelOrder(const int& id);   // Returns true if successful

    const double getBestBid() const;
    const double getBestAsk() const;

    void printOrderBook() const;
};