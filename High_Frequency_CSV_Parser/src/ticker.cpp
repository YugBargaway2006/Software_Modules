#include <string>
#include <vector>
#include <stdexcept>
#include "../include/ticker.h"


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


void Ticker::add_size(const int size) {
    accumulated_size += size;
}


void Ticker::add_cost(const double cost) {
    accumulated_price += cost;
}


