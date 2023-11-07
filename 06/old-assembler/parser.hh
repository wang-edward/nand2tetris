#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

enum InstructionType {
	C_INSTRUCTION,
	A_INSTRUCTION,
	L_INSTRUCTION
};

struct InstructionMapping {
  map<string, string> dest;
  map<string, string> comp;
  map<string, string> jump;
public:
  explicit InstructionMapping();
};

class Parser {
// private:
public:
  InstructionMapping im;
	ifstream file;
	string curr_line;
  string curr_dest, curr_comp, curr_jump;
	InstructionType type;
  string convert(const map<string, string> &m, string s) const;
  void updateC();
	
 //public:
	Parser(string filename);
	bool hasMoreLines();
	void advance();
	InstructionType parseInstruction(const string &s) const;
	InstructionType instructionType() const;
	string symbol() const;
	string dest() const;
	string comp() const;
	string jump() const;
};

ostream &operator<<(ostream &out, InstructionType it);
