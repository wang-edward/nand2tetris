#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

enum InstructionType {
	C_INSTRUCTION,
	A_INSTRUCTION,
	L_INSTRUCTION
};

class Parser {
// private:
public:
    std::ifstream file;
	std::string curr_line;
    std::regex space_regex{"\\s+"};	
    std::string curr_dest, curr_comp, curr_jump;
	InstructionType type;
    void updateC();
	
 //public:
	Parser(std::string filename);
	bool hasMoreLines();
	void advance();
	InstructionType parseInstruction(const std::string &s) const;
	InstructionType instructionType() const;
	std::string symbol() const;
	std::string dest() const;
	std::string comp() const;
	std::string jump() const;
};

std::ostream &operator<<(std::ostream &out, InstructionType it);
