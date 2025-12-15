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
    double fast_old_ema = 0;
    double slow_old_ema = 0;
    double fast_new_ema = 0;
    double slow_new_ema = 0;
    double fast_alpha = 0.1;
    double slow_alpha = 0.01;
    
    double calculate_vwap();
    void calculate_ema(const double& price);
    void update_signal();
    
public:
    double vwap = 0;
    size_t count = 0;
    size_t num_buys = 0;
    size_t num_sells = 0;

    Ticker(int timestamp, int size, double price, const std::string& symbol) 
        : timestamp(timestamp)
        , accumulated_size(size)
        , accumulated_price(price)
        , symbol(symbol)
    {}

    double vwap_calculate();
    void add_size(const int size);
    void add_cost(const double cost);
    void ema_calculate(const double& price);
};


#endif