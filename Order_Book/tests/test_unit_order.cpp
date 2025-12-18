#include <gtest/gtest.h>
#include "../include/order.h"


/**
 * @brief test if Order object is initialized correctly.
 */
TEST(OrderUnitTest, NewOrderInitialisesCorrectly) {
    Order stock(1, 10, 100.15, Side::bid);

    EXPECT_EQ(stock.quantity, 10);
    EXPECT_DOUBLE_EQ(stock.price, 100.15);
}


/**
 * @brief test if throws value_error if value of num is greater than quantity.
 */
TEST(OrderUnitTest, ThrowsErrorForMoreRetrieval) {
    Order stock(1, 10, 100.15, Side::bid);

    EXPECT_THROW(stock.buy_some(20), std::runtime_error);
}


/**
 * @brief test if throws value_error if value of num is negative.
 */
TEST(OrderUnitTest, ThrowsErrorForNegativeRetrieval) {
    Order stock(1, 10, 100.15, Side::bid);

    EXPECT_THROW(stock.buy_some(-20), std::runtime_error);
}


/**
 * @brief test if gives correct price for buying x quantity.
 */
TEST(OrderUnitTest, CorrectRetrieval) {
    Order stock(1, 10, 100.15, Side::bid);

    EXPECT_DOUBLE_EQ(stock.buy_some(5), 500.75);
}


/**
 * @brief test if gives correct side of the stock for bid.
 */
TEST(OrderUnitTest, CorrectBidCategory) {
    Order stock(1, 10, 100.15, Side::bid);

    EXPECT_EQ(stock.find_side(), Side::bid);
}


/**
 * @brief test if gives correct side of the stock for ask.
 */
TEST(OrderUnitTest, CorrectAskCategory) {
    Order stock(1, 10, 100.15, Side::ask);

    EXPECT_EQ(stock.find_side(), Side::ask);
}


/**
 * @brief test if gives correct ID retrieval of the stock.
 */
TEST(OrderUnitTest, CorrectIdRetrieval) {
    Order stock(1, 10, 100.15, Side::ask);

    EXPECT_EQ(stock.Id(), 1);
}



