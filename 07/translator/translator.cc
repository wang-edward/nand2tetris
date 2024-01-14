#include "translator.hh"

namespace fs = std::filesystem;

Translator:: Translator(std::string input_filename, std::string output_filename, std::string directory_path) 
    : input_file{input_filename}, output_file{output_filename}, directory_path{directory_path} { 

    generateMap(codes, directory_path);

    std::string temp;
    std::regex space_regex{"\\S+"};
    std::regex segment_regex{"\\{segment\\}"};
    std::regex index_regex{"\\{index\\}"};

    while (getline(input_file, temp)) {
        std::list tokens = regexSplit(temp, space_regex);
        
        if (tokens.empty()) continue;

        std::string assembly = codes[tokens.front()];
        if (tokens.front() == "push" || tokens.front() == "pop") {
            tokens.pop_front();
            if (tokens.front() == "constant") {
                assembly = codes["constant"];
            }
            PushPop config{tokens.front(), tokens.back()};
            assembly = replaceConfig(config, assembly, segment_regex, index_regex);
        }
        output_file << assembly;
        std::cout << assembly << std::endl;
    }
}

Translator:: ~Translator() {
    output_file.close();
}

std::string replaceConfig(const PushPop &config, const std::string &assembly, const std::regex &segment_regex, const std::regex &index_regex) {
    std::string result =  std::regex_replace(assembly, segment_regex, config.segment);
    result = std::regex_replace(result, index_regex, config.index);
    return result;
}

std::list<std::string> regexSplit(const std::string &temp, std::regex &space_regex) {
    std::sregex_iterator regex_it(temp.begin(), temp.end(), space_regex);
    std::sregex_iterator end_it;
    std::list<std::string> result;
    for (; regex_it != end_it; ++regex_it) {
        result.push_back(regex_it->str());
    }
    return result;
}

void generateMap(std::map<std::string, std::string> &codes, std::string directory_path) {
    for (const auto &entry : fs::directory_iterator(directory_path)) {
        if (!entry.is_regular_file()) continue;

        std::ifstream file{entry.path()};

        if (!file.is_open()) continue;

        std::string file_contents{std::istreambuf_iterator<char>{file}, std::istreambuf_iterator<char>{}};
        std::string file_name = entry.path().filename().string();
        std::regex file_type("\\.[^\\.]+$");
        file_name = std::regex_replace(file_name, file_type, "");

        codes[file_name] = file_contents;
    }
}
