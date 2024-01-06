#pragma once
 
#include <string>
#include <unordered_map>
#include <fstream>

class SymbolTable {
    std::unordered_map<std::string, uint16_t> lut;
    uint16_t current_position;
    std::ifstream file;

public:
    SymbolTable(std::string filename);
    void generateLut();
};
