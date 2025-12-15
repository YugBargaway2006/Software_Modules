#include <iostream>
#include <vector>
#include <string>
#include "include/generator.h"
#include "include/parser.h"
#include "include/ticker.h"

/**
 * @brief Entrypoint for the complete csv parser.
 */
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int row = 10000000;
    int col = 4;
    std::vector<std::string> col_list = {"Timestamp", "Symbol", "Price", "Size"};
    std::string filename = "data/data.csv";
    std::vector<std::string> symbol_list = {"AAPL", "GOOG", "MSFT", "TSLA", "AMZN"};
    
    Generator generator(100.00, 1500.00, 5, 1, 1000, filename);
    
    generator.generate_csv(row, col, col_list, symbol_list);
    std::cout << "CSV successfully generated" << std::endl;

    std::cout << "Starting Computing VWAP: ti = 0ms" << std::endl;
    Parser parser(filename);
    const std::vector<Ticker> stocks = parser.compute(symbol_list);
    std::cout << "Ending Computing VWAP: tf = " << parser.time_taken << "ms" << std::endl;

    for(int i = 0; i < symbol_list.size(); i++) {
        std::cout << symbol_list[i] << " Buys: " << stocks[i].num_buys << " Sells: " << stocks[i].num_sells << std::endl; 
    }
}