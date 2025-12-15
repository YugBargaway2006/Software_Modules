#include <gtest/gtest.h>
#include "../include/generator.h"


/**
 * @brief test if generator object has file access for correct path.
 */
TEST(GeneratorUnitTest, NewGeneratorHasFileAccess) {
    Generator generator(100.00, 1500.00, 4, 1, 1000, "tests/test_data/test_data_1.csv");
    
    std::vector<std::string> col_list = {"Timestamp", "Symbol", "Price", "Size"};
    std::vector<std::string> symbol_list = {"AAPL", "GOOG", "MSFT", "TSLA", "AMZN"};

    EXPECT_NO_THROW(generator.generate_csv(1, 4, col_list, symbol_list));
}


/**
 * @brief test if generator object has no file access for incorrect path.
 */
TEST(GeneratorUnitTest, WrongFilenameNoAccess) {
    Generator generator(100.00, 1500.00, 4, 1, 1000, "");
    
    std::vector<std::string> col_list = {"Timestamp", "Symbol", "Price", "Size"};
    std::vector<std::string> symbol_list = {"AAPL", "GOOG", "MSFT", "TSLA", "AMZN"};

    EXPECT_THROW(generator.generate_csv(1, 4, col_list, symbol_list), std::runtime_error);
}


/**
 * @brief test if generator object adds a header row at top.
 */
TEST(GeneratorUnitTest, GenerateAddHeaderRow) {
    std::string filename = "tests/test_data/test_data_2.csv";
    Generator generator(100.00, 1500.00, 4, 1, 1000, filename);
    
    std::vector<std::string> col_list = {"Timestamp", "Symbol", "Price", "Size"};
    std::vector<std::string> symbol_list = {"AAPL", "GOOG", "MSFT", "TSLA", "AMZN"};

    EXPECT_NO_THROW(generator.generate_csv(0, 4, col_list, symbol_list));

    std::ifstream file(filename);
    std::string line;
    std::getline(file, line);

    EXPECT_EQ(line, "Timestamp,Symbol,Price,Size");
}


/**
 * @brief test if generator object adds provided numbers of rows.
 */
TEST(GeneratorUnitTest, GenerateAddRequiredRows) {
    std::string filename = "tests/test_data/test_data_3.csv";
    Generator generator(100.00, 1500.00, 4, 1, 1000, filename);
    
    std::vector<std::string> col_list = {"Timestamp", "Symbol", "Price", "Size"};
    std::vector<std::string> symbol_list = {"AAPL", "GOOG", "MSFT", "TSLA", "AMZN"};

    EXPECT_NO_THROW(generator.generate_csv(10, 4, col_list, symbol_list));

    std::ifstream file(filename);
    std::string line;
    int i = 0;
    while(std::getline(file, line)) {
        ++i;
    }

    EXPECT_EQ(i, 11);
}


/**
 * @brief stress test generator object for large number of rows.
 */
TEST(GeneratorUnitTest, GenerateStressTest) {
    std::string filename = "tests/test_data/test_data_4.csv";
    Generator generator(100.00, 1500.00, 4, 1, 1000, filename);
    
    std::vector<std::string> col_list = {"Timestamp", "Symbol", "Price", "Size"};
    std::vector<std::string> symbol_list = {"AAPL", "GOOG", "MSFT", "TSLA", "AMZN"};

    EXPECT_NO_THROW(generator.generate_csv(1000000, 4, col_list, symbol_list));

    std::ifstream file(filename);
    std::string line;
    int i = 0;
    while(std::getline(file, line)) {
        ++i;
    }

    EXPECT_EQ(i, 1000001);
}