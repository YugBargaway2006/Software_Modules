#include <gtest/gtest.h>
#include "../include/parser.h"
#include "../include/ticker.h"


/**
 * @brief test if parser object ignores empty string.
 */
TEST(ParserUnitTest, StringParserIgnoresEmpty) {
    Parser parser("tests/test_data/test_data_3.csv");

    const std::string line = "";
    std::vector<std::string> data = parser.custom_line_parser_inst(line);

    EXPECT_TRUE(data.empty());
}


/**
 * @brief test if parser object parses string correctly.
 */
TEST(ParserUnitTest, StringParserCorrectness) {
    Parser parser("tests/test_data/test_data_3.csv");

    const std::string line = "3,TSLA,1347.66,172\n";
    std::vector<std::string> data = parser.custom_line_parser_inst(line);

    std::vector<std::string> correct = {"3", "TSLA", "1347.66", "172"};

    EXPECT_EQ(data, correct);
}


/**
 * @brief test if parser object parses string correctly without \n for last line.
 */
TEST(ParserUnitTest, StringParserCorrectnessWithoutNewLine) {
    Parser parser("tests/test_data/test_data_3.csv");

    const std::string line = "3,TSLA,1347.66,172";
    std::vector<std::string> data = parser.custom_line_parser_inst(line);

    std::vector<std::string> correct = {"3", "TSLA", "1347.66", "172"};

    EXPECT_EQ(data, correct);
}


/**
 * @brief test if parser object has file access for correct path.
 */
TEST(ParserUnitTest, NewParserHasFileAccess) {
    Parser parser("tests/test_data/test_data_1.csv");

    std::vector<std::string> symbol_list = {"AAPL", "GOOG", "MSFT", "TSLA", "AMZN"};
    EXPECT_NO_THROW(parser.compute(symbol_list));
}


/**
 * @brief test if parser object has no file access for incorrect path.
 */
TEST(ParserUnitTest, WrongFilenameNoAccess) {
    Parser parser("tests/data/file.csv");

    std::vector<std::string> symbol_list = {"AAPL", "GOOG", "MSFT", "TSLA", "AMZN"};
    EXPECT_THROW(parser.compute(symbol_list), std::runtime_error);
}


/**
 * @brief test if parser object skips a header row at top.
 */
TEST(ParserUnitTest, SkipsHeaderRow) {
    Parser parser("tests/test_data/test_data_2.csv");

    std::vector<std::string> symbol_list = {"AAPL", "GOOG", "MSFT", "TSLA", "AMZN"};
    EXPECT_NO_THROW(parser.compute(symbol_list));
}


/**
 * @brief test if parser object parse provided numbers of rows.
 */
TEST(ParserUnitTest, ParseGivenRows) {
    Parser parser("tests/test_data/test_data_3.csv");

    std::vector<std::string> symbol_list = {"AAPL", "GOOG", "MSFT", "TSLA", "AMZN"};
    EXPECT_NO_THROW(parser.compute(symbol_list));
}


/**
 * @brief stress test parser object for large number of rows.
 */
TEST(ParserUnitTest, StressTestParseRows) {
    Parser parser("tests/test_data/test_data_4.csv");

    std::vector<std::string> symbol_list = {"AAPL", "GOOG", "MSFT", "TSLA", "AMZN"};
    EXPECT_NO_THROW(parser.compute(symbol_list));
}