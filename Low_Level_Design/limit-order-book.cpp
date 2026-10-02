/*
    Market-making algorithms rely on maintaining an ultra-fast, accurate view of the market. Your task today is to design an in-memory Limit Order Book for a single financial instrument (e.g., Apple stock).

    1. Primary Cabilities
    2. Scope Boundaries
    3. Error Handling


    Requirements : 
    1. We can place order and store it in a book
    2. We need to have ability to cancel the order 
    3. Getters to best bid and best ask

    Error Handling : 
    1. Order_Id is unique and Side is Bid or Ask by pre-condition
    2. Price and Quantity is positive by pre-condition
    3. best bid and best ask, if not present, then we will (0, 0)

    Scope Boundaries : 
    1. we will not be considering about the matching logic.


    Entities : 
    1. Order
    2. Order Book


    Class Design :

*/

#include <bits/stdc++.h>
using namespace std;


enum SIDE {
    BID,
    ASK
};

struct Order {
    int order_id;
    SIDE side;
    int price;
    int quantity;
};

class OrderBook {
private:
    int book_size; 
    Order* order_pool; 
    queue<int> remaining_order_counter;

    std::unordered_map<int, std::list<Order>::iterator> order_lookup;
    std::map<int, std::list<Order>, std::greater<int>> bids;
    std::map<int, std::list<Order>, std::less<int>> asks;

    map<int, int> lookup_idx;

public:
    OrderBook() {
        book_size = 100000;
        order_pool = new Order[book_size];
        for(int i = 0; i < book_size; i++) {
            remaining_order_counter.push(i);
        }
    }

    ~OrderBook() {
        delete[] order_pool;
    }

    Order get_best_bid();
    Order get_best_ask();

    void place_order(int order_id, SIDE side, int price, int quantity) 
    /*
        Logic Flow : 
        1. Fetch an order from the queue
        2. Create an object of order class
        3. On the bid or ask, it will store the data in respective map
        4. Store the valid iterator in lookup table

        Edge Cases :
        1. Queue empty -> throw
    */

    {
        int idx = remaining_order_counter.front();
        remaining_order_counter.pop();

        Order& currOrder = order_pool[idx];
        currOrder.order_id = order_id;
        currOrder.side = side;
        currOrder.price = price;
        currOrder.quantity = quantity;

        lookup_idx[order_id] = idx;

        if(side == BID) {
            bids[price].emplace_back(currOrder);
            auto it = prev(bids[price].end());
            order_lookup[order_id] = it;
        }
        else {
            asks[price].emplace_back(currOrder);
            auto it = prev(asks[price].end());
            order_lookup[order_id] = it;
        }
    }


    void cancel_order(int order_id) 
    /*
        Logical Flow :
        1. Check if order id is in table, if not, just return
        2. Take the iterator from the lookup_table
        3. Erase the iterator from the respective book
        4, Erase the order_id from lookup_table
        5. Add the corresponding index to remaining_order_counter
        
        Edge Cases :
        1. If order not present, just return
    */
    {
        if(order_lookup.count(order_id) == 0) {
            return;
        }

        auto it = order_lookup[order_id];
        if(it->side == BID) {
            bids[it->price].erase(it);
        }
        else {
            asks[it->price].erase(it);
        }

        order_lookup.erase(order_id);
        remaining_order_counter.push(lookup_idx[order_id]);
    }
    
};