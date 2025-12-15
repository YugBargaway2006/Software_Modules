#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <fstream>
#include "ticker.h"


class Parser {
private:
    std::ifstream file;

    const std::vector<Ticker> compute_signal(std::vector<std::string>& symbol_list);
    std::vector<std::string> custom_line_parser(const std::string& line);
    size_t calculate_idx(const char& c1, const char& c2);
    inline int fast_atoi(const char*& p);
    inline double fast_atof(const char*& p);

public:
    std::string filename;
    int time_taken;

    Parser(std::string filename) 
        : filename(filename)
        , file(filename, std::ios::binary | std::ios::ate)
    {}

    const std::vector<Ticker> compute(std::vector<std::string>& symbol_list);
    std::vector<std::string> custom_line_parser_inst(const std::string& line);
};


#endif