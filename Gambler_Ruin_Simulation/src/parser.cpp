#include <string>
#include <vector>
#include <fstream>
#include <chrono>
#include "../include/parser.h"
#include "../include/ticker.h"
#include <map>


/**
 * @brief public instance of the compute_vwap function 
 */
const std::vector<Ticker> Parser::compute(std::vector<std::string>& symbol_list) {
    return compute_signal(symbol_list);
}


/**
 * @brief computes vwap for each stock and store it in the vwap attribute of stock ticker.
 *
 * @param none
 *
 * @pre file shall be open with ifstream to parse read
 *
 * @return nothing, but creates a ticker object for each stock data containing timestamp, price, symbol, size and vwap.
 *
 * @post the generated ticker objects should have vwap attribute filled with correct value.
 *
 * @throws runtime_error if the file cannot be open to read.
 *
 * @invariant method changes nothing from parser and ticker classes except vmap in each ticker object
 *
 * @complexity Time complexity O(row * col).
 */
const std::vector<Ticker> Parser::compute_signal(std::vector<std::string>& symbol_list) {
    auto start = std::chrono::steady_clock::now();

    if(!file.is_open()) {
        throw std::runtime_error("File cannot open for reading!");
    }

    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<char> buffer(size);
    if(!file.read(buffer.data(), size)) {
        throw std::runtime_error("Error loading buffer!");
    }

    const char* curr = buffer.data();
    const char* end = buffer.data() + size;

    int symbol_size = symbol_list.size();
    std::string line;
    std::vector<Ticker> stocks; 

    for(int i = 0; i < symbol_size; i++) {\
        Ticker stock(i+1, 1, 1, (const std::string)symbol_list[i]);     // #TODO Fix
        stocks.push_back(stock);
    }

    bool header = true;
    while(curr < end && *curr != '\n') {
        curr++;
    }
    curr++;
    header = false;

    while(curr < end) {
        while(*curr != ',') curr++;  // Skip timestamp
        curr++;

        size_t idx = calculate_idx(*curr, *(curr + 1));

        while(*curr != ',') curr++;  // Skip Symbol
        curr++;

        double price = fast_atof(curr); 
        curr++;

        int size = fast_atoi(curr);

        stocks[idx].ema_calculate(price);
    }

    auto time_end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(time_end - start);
    time_taken = duration.count();

    return stocks;
}


/**
 * @brief converts strings to integer values
 *
 * @param p the starting char pointer of the integer value to parse.
 *
 * @pre there shall be a integer value with the starting pointer as the first number of that integer.
 *
 * @return parsed integer
 *
 * @post the pointer is updated to the end of the integer in the string.
 *
 * @invariant string line remains invariant
 *
 * @complexity Time complexity O(|length of number|).
 */
inline int Parser::fast_atoi(const char*& p) {
    int x = 0;
    while (*p >= '0' && *p <= '9') {
        x = (x * 10) + (*p - '0');
        p++;
    }
    return x;
}


/**
 * @brief converts strings to float values
 *
 * @param p the starting char pointer of the float value to parse.
 *
 * @pre there shall be a float value with the starting pointer as the first number of that float with a decimal and some values preceding.
 *
 * @return parsed float value
 *
 * @post the pointer is updated to the end of the float in the string.
 *
 * @invariant string line remains invariant
 *
 * @complexity Time complexity O(|length of number|).
 */
inline double Parser::fast_atof(const char*& p) {
    double x = 0.0;
    
    while (*p >= '0' && *p <= '9') {
        x = (x * 10.0) + (*p - '0');
        p++;
    }
    
    if (*p == '.') {
        p++;
        double factor = 0.1;
        while (*p >= '0' && *p <= '9') {
            x += (*p - '0') * factor;
            factor *= 0.1;
            p++;
        }
    }
    return x;
}


/**
 * @brief maps the symbol to the storage in the ticker.
 *
 * @param c1 the starting char of the symbol to parse.
 * @param c2 the second starting char of the symbol to parse.
 *
 * @pre there shall be a valid symbol that is already present in the symbol list.
 *
 * @return mapped index value.
 *
 * @post no change in the pointer of the string data.
 *
 * @invariant string line remains invariant
 *
 * @complexity Time complexity O(1).
 */
size_t Parser::calculate_idx(const char& c1, const char& c2) {
    if(c1 == 'A' && c2 == 'A') return 0;
    if(c1 == 'A' && c2 == 'M') return 4;
    if(c1 == 'G') return 1;
    if(c1 == 'M') return 2;
    if(c1 == 'T') return 3;
    else return -1;
}


/**
 * @brief public instance of the line_parser function for testing 
 */
std::vector<std::string> Parser::custom_line_parser_inst(const std::string& line) {
    return custom_line_parser(line);
}


/**
 * @brief parses each line and segregates all data seperated by comma ",".
 *
 * @param line string containing all the data to be extracted.
 *
 * @pre string line shall be a valid string.
 *
 * @return a vector of string of all extracted data from the string.
 *
 * @post returned vector contains data in order {timestamp, symbol, price, size} 
 *
 * @invariant All the params are const and thus object is invariant.
 *
 * @complexity Time complexity O(|line|).
 */
std::vector<std::string> Parser::custom_line_parser(const std::string& line) {
    std::vector<std::string> data;

    std::string value = "";
    for(auto& c : line) {
        if(c == '\n') {
            data.push_back(value);
            value = "";
            break;
        }
        if(c == ',') {
            data.push_back(value);
            value = "";
        } else {
            value += c;
        }
    }
    if(value != "") {
        data.push_back(value);
    }

    return data;

} 