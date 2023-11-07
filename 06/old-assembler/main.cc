#include "parser.hh"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	Parser p{"Add.asm"};

  auto it = p.im.comp.find("A");
  if (it != p.im.comp.end()) {
    cout << it->second << endl;
  } else {
    cout << "not found " << endl;
    exit (123);
  }

  // for (auto x : p.im.dest) {
  //   cout << "[" << x.first << ", " << x.second << "]" << endl;
  // }

  // cout << "_-------------------------" << endl;

  // for (auto x : p.im.comp) {
  //   cout << "[" << x.first << ", " << x.second << "]" << endl;
  // }
  // 
  // cout << "_-------------------------" << endl;

  // for (auto x : p.im.jump) {
  //   cout << "[" << x.first << ", " << x.second << "]" << endl;
  // }

	while (p.hasMoreLines()) {
		p.advance();
    if (p.instructionType() == C_INSTRUCTION) {
      cout << "Dest: [" << p.dest() << "], Comp: [" << p.comp() << "], Jump: [" << p.jump() << "]" << endl;
    }
	}
}

