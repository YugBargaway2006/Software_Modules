#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <exception>
#include "../include/generator.h"


/**
 * @brief public instance of the generate_random_csv function 
 */
void Generator::generate_csv(const int row, const int col, const std::vector<std::string>& col_list, const std::vector<std::string>& symbol_list) {
    generate_random_csv(row, col, col_list, symbol_list);
}


/**
 * @brief creates a data.csv file filled with random data containing "row" rows and "col" columns.
 *
 * @param row number of rows required in the generated file
 * @param col number of columns required in the generated file
 * @param col_list name of the columns present in the generated file.
 * @param symbol_list ticker symbols to be generated randomly in the symbols column.
 *
 * @pre row and col must be a positive integer
 * @pre col_list size must be equal to the col value
 * @pre symbol_list must contain positive number of values.
 *
 * @return nothing, but creates a data.csv file in ${PROJECT_SOURCE_DIR}/data
 *
 * @post the generated file contains "row" rows, "col" columns with column names as present in the col_list.
 *          The values in the symbols column are randomly taken from symbol_list.
 *
 * @throws runtime_error if the file cannot be open to write.
 *
 * @invariant All the params are const and thus invariant.
 *
 * @complexity Time complexity O(row * col).
 */
void Generator::generate_random_csv(const int row, const int col, const std::vector<std::string>& col_list, const std::vector<std::string>& symbol_list) {
    if(!file.is_open()) {
        throw std::runtime_error("File cannot open for editing!");
    }

    for(int j = 0; j < col; j++) {
        file << col_list[j];
        if(j < col - 1) file << ",";
    }
    file << "\n";

    for(int i = 0; i < row; i++) {
        file << i + 1 << ",";
        file << symbol_list[((distrib_symbol(gen_symbol)) % max_num_symbols)] << ",";
        file << distrib_price(gen_price) << ",";
        file << distrib_size(gen_size) << "\n";
    }

    file.close();
}


