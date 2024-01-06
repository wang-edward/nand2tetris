#pragma once
#include <unordered_map>
#include <string>
#include <stdexcept>

class Code {
private:
    std::unordered_map<std::string, std::string> map_dest;
    std::unordered_map<std::string, std::string> map_comp;
    std::unordered_map<std::string, std::string> map_jump;
    
public:
    explicit Code();
    std::string convertDest(const std::string &s) const;
    std::string convertComp(const std::string &s) const;
    std::string convertJump(const std::string &s) const;

};

std::string convert(const std::unordered_map<std::string, std::string> &m, const std::string &s);
