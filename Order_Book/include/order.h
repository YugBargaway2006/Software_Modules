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

    Order(const int& id, const int& qunatity, const double& price, const Side side)
    : id(id)
    , quantity(quantity)
    , price(price)
    , side(side)
    {}

    const double buy_some(const int& num);
    const Side& Side();
    const int& Id();
};
