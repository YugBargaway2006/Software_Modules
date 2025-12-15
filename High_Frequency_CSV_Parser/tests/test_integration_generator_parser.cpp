#include <gtest/gtest.h>
#include "../include/parser.h"
#include "../include/ticker.h"
#include "../include/generator.h"


/**
 * @brief test if complete integration of Generator and Parser working correctly.
 */
TEST(GeneratorParserIntegrationTest, CompletePipelineWorkingCorrectness) {
    int row = 10;
    int col = 4;
    std::vector<std::string> col_list = {"Timestamp", "Symbol", "Price", "Size"};
    std::string filename = "tests/test_data/test_data_5.csv";
    std::vector<std::string> symbol_list = {"AAPL", "GOOG", "MSFT", "TSLA", "AMZN"};
    
    Generator generator(100.00, 1500.00, 5, 1, 1000, filename);
    
    generator.generate_csv(row, col, col_list, symbol_list);

    Parser parser(filename);
    EXPECT_NO_THROW(parser.compute(symbol_list));
}