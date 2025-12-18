#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <memory>
#include <algorithm>
#include "../include/order_book.h"
#include "../include/order.h"


/**
 * @brief takes the order, check if a probable trade exist and perform. Store the remaining amount into the lookup table.
 *
 * @param id order_id of the trade
 * @param quantity quantity of the trade
 * @param price price of the trade
 * @param side whether the trade is a bid or ask.
 *
 * @pre id must be a unique number and side cannot be anything else than bid / ask. Price and quantity must be a non-negative numeral.
 *
 * @return store the remaining order into the lookup table
 *
 * @invariant All the params are const and thus invariant, only quantity changes. Lookup table and storage changes.
 *
 * @complexity Time complexity O(quantity).
 */
void Order_Book::addOrder(const int& id, const int& quantity, const double& price, const Side& side) {
    if(quantity < 0) return;

    int qt = quantity;
    if(side == Side::bid) {
        while(qt > 0 && !asks.empty()) {
            auto best_ask = asks.begin();
            double ask_price = best_ask->first;
            auto& sellers = best_ask->second;

            if(price < ask_price) break;

            while(qt > 0 && !sellers.empty()) {
                auto order = sellers.front();
                int sell_qt = std::min(qt, order->quantity);

                std::cout << "Trade! " << sell_qt << " @ " << ask_price << "\n";   // Trade

                order->quantity -= sell_qt;
                qt -= sell_qt;

                if(order->quantity == 0) {
                    lookup_table.erase(order->Id()); 
                    sellers.pop_front();
                }
            }

            if(asks.begin()->second.empty()) {
                asks.erase(asks.begin());
            }
        }
    }
    else {
        while(qt > 0 && !bids.empty()) {
            auto best_bid = bids.begin();
            double bid_price = best_bid->first;
            auto& buyers = best_bid->second;

            if(price > bid_price) break;

            while(qt > 0 && !buyers.empty()) {
                auto order = buyers.front();
                int buy_qt = std::min(qt, order->quantity);

                std::cout << "Trade! " << buy_qt << " @ " << bid_price << "\n";   // Trade

                order->quantity -= buy_qt;
                qt -= buy_qt;

                if(order->quantity == 0) {
                    lookup_table.erase(order->Id()); 
                    buyers.pop_front();
                }
            }

            if(bids.begin()->second.empty()) {
                bids.erase(bids.begin());
            }
        }
    }

    if(qt > 0) {
        std::shared_ptr<Order> newOrder = std::make_shared<Order>(id, qt, price, side);
        lookup_table[id] = newOrder;
        
        if(side == Side::bid) {
            bids[price].push_back(newOrder);
        }
        else if(side == Side::ask) {
            asks[price].push_back(newOrder);
        }
    }
}


/**
 * @brief removes the order from the storage and lookup table if required.
 *
 * @param id order_id of the order.
 *
 * @pre id must be a valid stored order
 *
 * @return true if the order is removed successfully else false.
 *
 * @invariant All the params are const and thus invariant, only lookup table and storage changes.
 *
 * @complexity Time complexity O(log(n)).
 */
bool Order_Book::cancelOrder(const int& id) {
    auto it = lookup_table.find(id);
    if(it == lookup_table.end()) return false;

    std::shared_ptr<Order> stock = it->second;
    double price = stock->price;

    if(stock->find_side() == Side::bid) {
        bids[price].remove(stock);
        if(bids[price].empty()) bids.erase(price);
    }
    else if(stock->find_side() == Side::ask) {
        asks[price].remove(stock);
        if(asks[price].empty()) asks.erase(price);
    } 

    lookup_table.erase(it);
    return true;
}


/**
 * @brief public instance to view the best (highest) bid
 */
const double Order_Book::getBestBid() const {
    if(bids.empty()) return -1;
    double bestbid = bids.begin()->first;
    return bestbid;
}


/**
 * @brief public instance to view the best (lowest) ask 
 */
const double Order_Book::getBestAsk() const {
    if(asks.empty()) return -1;
    double bestask = asks.begin()->first;
    return bestask;
}


/**
 * @brief public instance to view the complete order book
 */
void Order_Book::printOrderBook() const {
    printf("\n\n");
    std::cout << "------------ BIDS TABLE --------------" << std::endl;
    for(const auto&[price, order_list] : bids) {
        for(const auto& order : order_list) {
            std::cout << "ID: " << order->Id() << " Qt: " << order->quantity << " Price: $" << order->price << " Side: Bid" << std::endl;
        }
    }
    printf("\n\n");

    std::cout << "------------ ASKS TABLE --------------" << std::endl;
    for(const auto&[price, order_list] : asks) {
        for(const auto& order : order_list) {
            std::cout << "ID: " << order->Id() << " Qt: " << order->quantity << " Price: $" << order->price << " Side: Ask" << std::endl;
        }
    }
    printf("\n\n");
}


