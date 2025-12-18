#include <string>
#include <vector>
#include <stdexcept>
#include "../include/order.h"


/**
 * @brief calculates price of stocks when there is a requirement of a fraction of total amount.
 *
 * @param num total number of stocks to buy.
 *
 * @pre num both must be a non-negative integer less than quantity.
 *
 * @return the price of required stocks and updated the new quantity to the stock.
 *
 * @invariant All the params are const and thus invariant, only quantity changes.
 *
 * @complexity Time complexity O(1).
 */
const double Order::buy_some(const int& num) {
    if(num > quantity || num < 0) {
        throw std::runtime_error("Invalid number of stocks to buy.");
    }
    
    quantity -= num;
    return num * price;
}


/**
 * @brief public instance to view the side variable 
 */
const Side& Order::find_side() const {
    return side;
}


/**
 * @brief public instance to view the Id variable 
 */
const int& Order::Id() const {
    return id;
}


