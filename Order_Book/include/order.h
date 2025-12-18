#pragma once

#include <string>


enum class Side {
    bid,
    ask
};


class Order {
private:
    const int id;
    const Side side;

public:
    int quantity;
    const double price;

    Order(const int& id, const int& quantity, const double& price, const Side side)
    : id(id)
    , quantity(quantity)
    , price(price)
    , side(side)
    {}

    const double buy_some(const int& num);
    const Side& find_side() const;
    const int& Id() const;
};
