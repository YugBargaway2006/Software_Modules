#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <memory>
#include <algorithm>
#include "../include/order_book.h"
#include "../include/order.h"
#include "../include/order_pool.h"


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

    int tick = (int)(price * 100);

    int qt = quantity;
    if(side == Side::bid) {
        while(qt > 0 && min_ask_tick < asks.size()) {
            auto& sellers = asks[min_ask_tick];
            // double ask_price = (double)((min_ask_tick*1.0)/100);
            double ask_price = min_ask_tick;

            if(tick < min_ask_tick) break;

            while(qt > 0 && !sellers.empty()) {
                auto order = sellers.front();
                int sell_qt = std::min(qt, order->quantity);

                // std::cout << "Trade! " << sell_qt << " @ " << ask_price << "\n";   // Trade
                trade_log.push_back(TradeRecord(id, order->Id(), sell_qt, ask_price));

                order->quantity -= sell_qt;
                qt -= sell_qt;

                if(order->quantity == 0) {
                    lookup_table.erase(order->Id()); 
                    sellers.pop_front();
                    order_pool.release(order);
                }
            }

            if(asks[min_ask_tick].empty()) {
                min_ask_tick++;
            }
        }
    }
    else {
        while(qt > 0 && max_bid_tick > 0) {
            auto& buyers = bids[max_bid_tick];
            // double bid_price = (double)((max_bid_tick*1.0)/100);
            double bid_price = max_bid_tick;

            if(tick > max_bid_tick) break;

            while(qt > 0 && !buyers.empty()) {
                auto order = buyers.front();
                int buy_qt = std::min(qt, order->quantity);

                // std::cout << "Trade! " << buy_qt << " @ " << bid_price << "\n";   // Trade
                trade_log.push_back(TradeRecord(id, order->Id(), buy_qt, bid_price));

                order->quantity -= buy_qt;
                qt -= buy_qt;

                if(order->quantity == 0) {
                    lookup_table.erase(order->Id()); 
                    buyers.pop_front();
                    order_pool.release(order);
                }
            }

            if(bids[max_bid_tick].empty()) {
                max_bid_tick--;
            }
        }
    }

    if(qt > 0) {
        Order* newOrder = order_pool.acquire(id, qt, price, side);
        lookup_table[id] = newOrder;
        
        if(side == Side::bid) {
            bids[tick].push_back(newOrder);
            max_bid_tick = std::max(max_bid_tick, tick);
        }
        else if(side == Side::ask) {
            asks[tick].push_back(newOrder);
            min_ask_tick = std::min(min_ask_tick,   tick);
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

    Order* stock = it->second;
    double price = stock->price;
    int tick = (int)(price*100);

    if(stock->find_side() == Side::bid) {
        bids[tick].remove(stock);
        if(tick == max_bid_tick && bids[tick].empty()) max_bid_tick--;
    }
    else if(stock->find_side() == Side::ask) {
        asks[tick].remove(stock);
        if(tick == min_ask_tick && asks[tick].empty()) min_ask_tick++;
    } 

    lookup_table.erase(it);
    order_pool.release(stock);
    return true;
}


/**
 * @brief public instance to view the best (highest) bid
 */
const double Order_Book::getBestBid() const {
    if(bids.empty()) return -1;
    double bestbid = (max_bid_tick*1.0)/100;
    return max_bid_tick;
}


/**
 * @brief public instance to view the best (lowest) ask 
 */
const double Order_Book::getBestAsk() const {
    if(asks.empty()) return -1;
    double bestask = (min_ask_tick*1.0)/100;
    return min_ask_tick;
}


/**
 * @brief public instance to view the complete order book
 */
void Order_Book::printOrderBook() const {
    printf("\n\n");
    std::cout << "------------ BIDS TABLE --------------" << std::endl;
    for(int i = max_bid_tick; i >= 0; i--) {
        for(const auto& order : bids[i]) {
            std::cout << "ID: " << order->Id() << " Qt: " << order->quantity << " Price: $" << order->price << " Side: Bid" << std::endl;
        }
    }
    printf("\n\n");

    std::cout << "------------ ASKS TABLE --------------" << std::endl;
    for(int i = min_ask_tick; i < asks.size(); i++) {
        for(const auto& order : asks[i]) {
            std::cout << "ID: " << order->Id() << " Qt: " << order->quantity << " Price: $" << order->price << " Side: Ask" << std::endl;
        }
    }
    printf("\n\n");
}


/**
 * @brief public instance to view the complete trade log
 */
void Order_Book::flushlog() const {
    for(auto& trade : trade_log) {
        trade.print_record();
    }
}


