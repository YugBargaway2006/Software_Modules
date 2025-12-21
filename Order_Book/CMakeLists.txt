cmake_minimum_required(VERSION 3.10)

project(OrderBook LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_compile_options(-O3 -march=native)

#
# * Order Library
#
add_library(Order
    src/order.cpp
)

target_include_directories(Order
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

#
# * Order_Pool Library
#
add_library(Order_Pool
    src/order_pool.cpp
)

target_include_directories(Order_Pool
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

#
# * Trade_Record Library
#
add_library(Trade_Record
    src/trade_record.cpp
)

target_include_directories(Trade_Record
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

#
# * Order_Book Library
#
add_library(Order_Book
    src/order_book.cpp
)

target_include_directories(Order_Book
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(Order_Book
    PUBLIC
        Order
        Trade_Record
        Order_Pool
)


#
# * Market Data Receiver Library
#
add_library(Order_Book
    src/market_data_receiver.cpp
)

target_include_directories(Market_Data_Receiver
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(Market_Data_Receiver
    PUBLIC
        Order
        Order_Book
        Protocol
)



add_executable(OrderBook
    main.cpp
)

target_link_libraries(OrderBook
    PRIVATE
        Order
        Order_Book
        Trade_Record
        Order_Pool
)


#
# * Testing
#
enable_testing()
find_package(GTest REQUIRED)

add_executable(Testing
    tests/test_main.cpp
    tests/test_unit_order.cpp
    tests/test_unit_order_book.cpp
)

target_link_libraries(Testing
    PRIVATE
        Order_Book
        Order
        Trade_Record
        Order_Pool
        GTest::gtest
        pthread
)

add_test(NAME Testing COMMAND Testing)