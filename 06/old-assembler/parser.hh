export module Parser;

import <iostream>;
import <fstream>;
import <sstream>;

using namespace std;

enum InstructionType {
	C_INSTRUCTION,
	A_INSTRUCTION,
	L_INSTRUCTION
};

class Parser {
	ifstream file;
	string curr_line;
	
 // public:
	explicit Parser(ifstream file);
	bool hasMoreLines();
	void advance();
	InstructionType instructionType();
	string symbol();
	string dest();
	string comp();
	string jump();
};
