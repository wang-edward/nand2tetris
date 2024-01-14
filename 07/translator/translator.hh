#include <fstream>
#include <iostream>
#include <filesystem>
#include <map>

class Translator {
    std::ifstream input_file;
    std::string directory_path;
    std::map<std::string, std::string> codes;
public:
    Translator(std::string directory_path);
};
