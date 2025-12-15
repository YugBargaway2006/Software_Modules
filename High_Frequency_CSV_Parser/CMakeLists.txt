cmake_minimum_required(VERSION 3.10)

project(VWAPCalculator LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_compile_options(-O3 -march=native)

#
# * Generator Library
#
add_library(generator
    src/generator.cpp
)

target_include_directories(generator
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

#
# * Parser Library
#
add_library(parser
    src/parser.cpp
)

target_include_directories(parser
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

#
# * Ticker Library
#
add_library(ticker
    src/ticker.cpp
)

target_include_directories(ticker
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)


add_executable(vwap_calculator
    main.cpp
)

target_link_libraries(vwap_calculator
    PRIVATE
        generator
        parser
        ticker
)


#
# * Testing
#
enable_testing()
find_package(GTest REQUIRED)

add_executable(Testing
    tests/test_main.cpp
    tests/test_unit_generator.cpp
    tests/test_unit_ticker.cpp
    tests/test_unit_parser.cpp
    tests/test_integration_generator_parser.cpp
)

target_link_libraries(Testing
    PRIVATE
        generator
        parser
        ticker
        GTest::gtest
        pthread
)

add_test(NAME Testing COMMAND Testing)