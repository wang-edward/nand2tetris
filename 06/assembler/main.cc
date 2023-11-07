#include "parser.hh"
#include "code.hh"
#include <iostream>
#include <fstream>

using namespace std;

string generate_filepath(const string &s) {
  size_t index_end = s.find('.');
  return (s.substr(0, index_end) + ".hack");
}

int main(int argc, char **argv) {
  if (argc != 2) {
    cout << "1 argument lil bro" << endl;
    exit(1);
  }

	Parser p{argv[1]};
  Code c;
  ofstream fout{generate_filepath(argv[1])};

	while (p.hasMoreLines()) {
		p.advance();
    switch (p.instructionType()) {
      case C_INSTRUCTION:
        fout << "111" << c.dest(p.dest()) << c.comp(p.comp()) << c.jump(p.jump()) << endl;
        break;
      case A_INSTRUCTION:
        int numeral = stoi(p.symbol());
        string binary = std::bitset<16>(numeral).to_string(); //to binary
        fout << binary << endl;
        break;
    }
	}
  fout.close();
}

