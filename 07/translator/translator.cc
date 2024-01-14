#include "translator.hh"

namespace fs = std::filesystem;

Translator:: Translator(std::string directory_path) {
    for (const auto &entry : fs::directory_iterator(directory_path)) {
        if (!entry.is_regular_file()) continue;

        std::ifstream file{entry.path()};

        if (!file.is_open()) continue;

        std::string file_contents{std::istreambuf_iterator<char>{file}, std::istreambuf_iterator<char>{}};
        std::string file_name = entry.path().filename().string();

        codes[file_name] = file_contents;
    }

    for (auto x : codes) {
        std::cout << x.second << std::endl;
    }
}
