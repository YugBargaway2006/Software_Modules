#pragma once

#include <vector>


class TradeRecord {
public:
    const int id;
    const int order_id;
    const int quantity;
    const double ask_price;

    TradeRecord(const int& id, const int& order_id, const int& quantity, const double& ask_price)
    : id(id)
    , order_id(order_id)
    , quantity(quantity)
    , ask_price(ask_price)
    {}

    void print_record() const;
};