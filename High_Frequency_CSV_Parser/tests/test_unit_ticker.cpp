#include <gtest/gtest.h>
#include "../include/ticker.h"


/**
 * @brief test if ticker object is initialized correctly.
 */
TEST(TickerUnitTest, NewTickerHasVwapZero) {
    Ticker stock(1, 10, 10.00, (const std::string)"AAPL");

    EXPECT_EQ(stock.vwap, 0);
}


/**
 * @brief test if throws runtime_error if value of size is zero.
 */
TEST(TickerUnitTest, ThrowsErrorForSizeZero) {
    Ticker stock(1, 0, 10.00, (const std::string)"AAPL");

    EXPECT_THROW(stock.vwap_calculate(), std::runtime_error);
}


/**
 * @brief test if ticker object is calculating correct VWAP.
 */
TEST(TickerUnitTest, CalculateVWAP) {
    Ticker stock(1, 10, 10.00, (const std::string)"AAPL");
    stock.vwap_calculate();

    EXPECT_EQ(stock.vwap, 10.00);
}