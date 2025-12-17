#include <gtest/gtest.h>
#include "../include/order.h"
#include "../include/order_book.h"


/**
 * @brief test if Order_book object is initialized correctly.
 */
TEST(OrderBookUnitTest, NewOrderBookInitialisesCorrectly) {
    EXPECT_NO_THROW(Order_Book book());
}


/**
 * @brief test if throws -1 if no best bid exist.
 */
TEST(OrderBookUnitTest, ThrowsErrorForNoBid) {
    Order_Book book;
    book.addOrder(1, 10, 100.25, "ask");
    book.addOrder(1, 10, 75.25, "ask");
    book.addOrder(1, 10, 150.00, "ask");

    EXPECT_DOUBLE_EQ(book.getBestBid(), -1);
}


/**
 * @brief test if best bid returns correct value.
 */
TEST(OrderBookUnitTest, GetBestBid) {
    Order_Book book;
    book.addOrder(1, 10, 100.25, "bid");
    book.addOrder(1, 10, 75.25, "bid");
    book.addOrder(1, 10, 150.00, "bid");

    EXPECT_DOUBLE_EQ(book.getBestBid(), 150.00);
}


/**
 * @brief test if throws -1 if no best ask exist.
 */
TEST(OrderBookUnitTest, ThrowsErrorForNoAsk) {
    Order_Book book;
    book.addOrder(1, 10, 100.25, "bid");
    book.addOrder(1, 10, 75.25, "bid");
    book.addOrder(1, 10, 150.00, "bid");

    EXPECT_DOUBLE_EQ(book.getBestAsk(), -1);
}


/**
 * @brief test if best bid returns correct value.
 */
TEST(OrderBookUnitTest, GetBestAsk) {
    Order_Book book;
    book.addOrder(1, 10, 100.25, "ask");
    book.addOrder(1, 10, 175.25, "ask");
    book.addOrder(1, 10, 150.00, "ask");

    EXPECT_DOUBLE_EQ(book.getBestAsk(), 175.25);
}



