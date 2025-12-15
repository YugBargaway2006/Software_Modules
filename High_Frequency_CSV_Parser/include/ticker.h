#ifndef TICKER_H
#define TICKER_H

#include <string>
#include <vector>


class Ticker {
private:
    int timestamp;
    int accumulated_size;
    double accumulated_price;
    std::string symbol;
    
    double calculate_vwap();
    
public:
    double vwap = 0;

    Ticker(int timestamp, int size, double price, const std::string& symbol) 
        : timestamp(timestamp)
        , accumulated_size(size)
        , accumulated_price(price)
        , symbol(symbol)
    {}

    double vwap_calculate();
    void add_size(const int size);
    void add_cost(const double cost);
};


#endif