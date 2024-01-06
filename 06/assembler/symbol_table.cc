#include "symbol_table.hh"

SymbolTable:: SymbolTable(std::string filename) : current_position{0x10}, file{filename} {}

bool isValidSymbol(std::string s) {
    return s.front() == '(' && s.back() == ')';
}

void SymbolTable:: generateLut() {
    std::string temp;
    while (getline(file, temp)) {
        if (isValidSymbol(temp));
    }
}


