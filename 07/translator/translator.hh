#include <fstream>
#include <iostream>
#include <filesystem>
#include <map>
#include <regex>
#include <list>

struct PushPop {
    std::string segment;
    std::string index;
};

class Translator {
    std::ifstream input_file;
    std::ofstream output_file;
    std::string directory_path;
    std::map<std::string, std::string> codes;
public:
    Translator(std::string input_filename, std::string output_filename, std::string directory_path);
    ~Translator();
};

std::string replaceConfig(const PushPop &config, const std::string &assembly, const std::regex &segment_regex, const std::regex &index_regex);
std::list<std::string> regexSplit(const std::string &temp, std::regex &space_regex);
void generateMap(std::map<std::string, std::string> &codes, std::string directory_path);
