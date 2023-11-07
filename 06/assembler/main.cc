#include "parser.hh"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	Parser p{"Pong.asm"};

	while (p.hasMoreLines()) {
		p.advance();
    if (p.instructionType() == C_INSTRUCTION) {
      cout << "Dest: [" << p.dest() << "], Comp: [" << p.comp() << "], Jump: [" << p.jump() << "]" << endl;
    }
	}
}

