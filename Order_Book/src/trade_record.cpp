#include <iostream>
#include "../include/trade_record.h"


/**
 * @brief public instance to view the complete record 
 */
void TradeRecord::print_record() const {
    std::cout << "Trade! ID1: " << id << " ID2: " << order_id << " Qt: " << quantity << " Price: " << ask_price << std::endl;
}


