#include <gtest/gtest.h>
#include "../include/market_data_receiver.h"
#include "../include/order_book.h"
#include <csignal>

/**
 * @brief test if MarketDataReceiver object initializes correctly.
 */
TEST(MarketDataReceiverUnitTest, ConstructorInitialisesCorrectly) {
    EXPECT_NO_THROW({
        MarketDataReceiver receiver("239.255.0.1", 30001);
    });
}


/**
 * @brief test if destructor closes safely without init().
 */
TEST(MarketDataReceiverUnitTest, DestructorWithoutInitDoesNotThrow) {
    EXPECT_NO_THROW({
        MarketDataReceiver receiver("239.255.0.1", 30001);
    });
}


/**
 * @brief test if init succeeds with valid multicast IP and port.
 */
TEST(MarketDataReceiverUnitTest, InitWithValidParameters) {
    MarketDataReceiver receiver("239.255.0.1", 30001);
    EXPECT_NO_THROW(receiver.init());
}


/**
 * @brief test if init throws for invalid multicast IP.
 */
TEST(MarketDataReceiverUnitTest, InitThrowsForInvalidIP) {
    MarketDataReceiver receiver("999.999.999.999", 30001);
    EXPECT_THROW(receiver.init(), std::runtime_error);
}


/**
 * @brief test if multiple init calls do not crash.
 */
TEST(MarketDataReceiverUnitTest, MultipleInitCallsSafe) {
    MarketDataReceiver receiver("239.255.0.1", 30001);
    EXPECT_NO_THROW(receiver.init());
    EXPECT_NO_THROW(receiver.init());
}


/**
 * @brief test if signal handler sets termination flag safely.
 */
TEST(MarketDataReceiverUnitTest, SignalHandlerDoesNotCrash) {
    EXPECT_NO_THROW({
        signal_handler(SIGINT);
    });
}


/**
 * @brief test if start() does not throw immediately with valid setup.
 *        (execution is intentionally short-lived)
 */
TEST(MarketDataReceiverUnitTest, StartDoesNotThrowImmediately) {
    MarketDataReceiver receiver("239.255.0.1", 30001);
    Order_Book book;

    receiver.init();

    // Raise signal before start to prevent blocking
    signal_handler(SIGINT);

    EXPECT_NO_THROW(receiver.start(book));
}
