#include "translator.hh"
#include <iostream>

std::string generate_filepath(const std::string &s) {
  size_t index_end = s.rfind('.');
  return (s.substr(0, index_end) + ".hack");
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Takes 1 argument: input filename.vm" << std::endl;
        exit(1);
    }

    std::string input_filename{argv[1]};
    std::string output_filename{generate_filepath(input_filename)};

    Translator t{input_filename, output_filename, "asm"};
}
