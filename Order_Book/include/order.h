#pragma once

#include <string>


class Order {
private:
    const int id;
    const char side;

public:
    int quantity;
    const double price;

    Order(const int& id, const int& qunatity, const double& price, const std::string& side)
    : id(id)
    , quantity(quantity)
    , price(price)
    , side(side[0])
    {}

    const double buy_some(const int& num);
    const std::string& Side();
    const int& Id();
};
