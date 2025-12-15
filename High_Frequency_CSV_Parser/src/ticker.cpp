#include <string>
#include <vector>
#include <stdexcept>
#include "../include/ticker.h"


/**
 * @brief public instance of the calculate_ema function 
 */
void Ticker::ema_calculate(const double& price){
    calculate_ema(price);
    update_signal();
}


/**
 * @brief calculates exponential moving average for a ticker
 *
 * @param fast_old_ema volume of the stock
 * @param slow_old_ema volume of the stock
 * @param price current price of the stock
 *
 * @pre price both must be a positive integer
 *
 * @return new_ema, that is, equal to (alpha * price + (1 - alpha) * old_ema).
 *
 * @invariant All the params are const and thus invariant, only ema_values changes.
 *
 * @complexity Time complexity O(1).
 */
void Ticker::calculate_ema(const double& price) {
    double fast_ema = fast_alpha * price + (1 - fast_alpha) * fast_new_ema;
    double slow_ema = slow_alpha * price + (1 - slow_alpha) * slow_new_ema;

    slow_old_ema = slow_new_ema;
    fast_old_ema = fast_new_ema;

    slow_new_ema = slow_ema;
    fast_new_ema = fast_ema;
    
    update_signal();
}


/**
 * @brief public instance of the calculate_vwap function 
 */
void Ticker::update_signal(){
    if((slow_old_ema > fast_old_ema && slow_new_ema < fast_new_ema)) {
        num_buys++;
    }
    if((slow_old_ema < fast_old_ema && slow_new_ema > fast_new_ema)) {
        num_sells++;
    }
}


/**
 * @brief public instance of the calculate_vwap function 
 */
double Ticker::vwap_calculate(){
    vwap = calculate_vwap();
    return vwap;
}


/**
 * @brief calculates volume weighted average price (vwap) for a ticker
 *
 * @param size volume of the stock
 * @param price current price of the stock
 *
 * @pre size and price both must be a positive integer
 *
 * @return vwap, that is, equal to volume * price divided by volume.
 *
 * @throws runtime_error if the value of size is zero.
 *
 * @invariant All the params are const and thus invariant.
 *
 * @complexity Time complexity O(1).
 */
double Ticker::calculate_vwap() {
    if(accumulated_size == 0) {
        throw std::runtime_error("Division by zero. Size of stock cannot be zero (0).");
    }
    return ((accumulated_size * 1.0 * accumulated_price) / (accumulated_size * 1.0));
}


/**
 * @brief add commulative size of a stock 
 */
void Ticker::add_size(const int size) {
    accumulated_size += size;
}


/**
 * @brief add commulative (cost = size * price) of a stock 
 */
void Ticker::add_cost(const double cost) {
    accumulated_price += cost;
}


