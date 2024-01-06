#include "parser.hh"
#include "code.hh"
#include <iostream>
#include <fstream>

std::string generate_filepath(const std::string &s) {
  size_t index_end = s.rfind('.');
  return (s.substr(0, index_end) + ".hack");
}

std::string make_string(const char *s) {
    return {s};
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "takes 1 argument: filename." << std::endl;
        exit(1);
    }

    Parser parser{argv[1]};
    Code code;
    std::ofstream fout{generate_filepath(argv[1])};
    try {
        parser.parse(fout, code);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
    fout.close();
}
