#pragma once

#include <map>
#include <vector>
#include <list>
#include <string>
#include <memory>
#include <unordered_map>
#include "order.h"
#include "order_pool.h"
#include "trade_record.h"


class Order_Book {
private:
    Order_Pool<Order> order_pool;
    std::map<double, std::list<Order*>, std::greater<double>> bids;   // Take the highest Bid First
    std::map<double, std::list<Order*>, std::less<double>> asks;      // Take the lowest ask first
    std::unordered_map<int, Order*> lookup_table;
    std::vector<TradeRecord> trade_log;

public:
    Order_Book() 
    : order_pool(1e5) 
    , trade_log(1e6)
    {}

    void addOrder(const int& id, const int& quantity, const double& price, const Side& side);
    bool cancelOrder(const int& id);   // Returns true if successful

    const double getBestBid() const;
    const double getBestAsk() const;

    void printOrderBook() const;
    void flushlog() const;
};