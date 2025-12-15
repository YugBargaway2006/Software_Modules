#ifndef GENERATOR_H
#define GENERATOR_H 

#include <fstream>
#include <vector>
#include <random>
#include <string>


class Generator {
private:
    double min_val_price;
    double max_val_price;
    int max_num_symbols;
    int min_val_size;
    int max_val_size;
    std::random_device rd;
    std::mt19937 gen_price;
    std::mt19937 gen_symbol;
    std::mt19937 gen_size;
    std::uniform_real_distribution<double> distrib_price;
    std::uniform_int_distribution<int> distrib_symbol;
    std::uniform_int_distribution<int> distrib_size;
    std::ofstream file;

    void generate_random_csv(const int row, const int col, const std::vector<std::string>& col_list, const std::vector<std::string>& symbol_list);

public:
    Generator(double min_val_price, double max_val_price, int max_num_symbols, int min_val_size, int max_val_size, const std::string& filename) 
        : min_val_price(min_val_price)
        , max_val_price(max_val_price)
        , max_num_symbols(max_num_symbols)
        , min_val_size(min_val_size)
        , max_val_size(max_val_size)
        , rd()
        , gen_price(rd())
        , gen_symbol(rd())
        , gen_size(rd())
        , distrib_price(min_val_price, max_val_price)
        , distrib_symbol(1, max_num_symbols)
        , distrib_size(min_val_size, max_val_size)
        , file(filename) 
    {}

    void generate_csv(const int row, const int col, const std::vector<std::string>& col_list, const std::vector<std::string>& symbol_list);
};


#endif