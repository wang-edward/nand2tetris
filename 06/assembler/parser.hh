#pragma once

#include <iostream>
#include <fstream>
#include <regex>

#include "code.hh"


enum InstructionType {
	C_INSTRUCTION,
	A_INSTRUCTION,
	L_INSTRUCTION,
};

class Parser {
    static constexpr uint16_t START_ADDRESS {0x10};
    static constexpr uint16_t END_ADDRESS {0x7FFF};

    std::ifstream file;
	std::string curr_line;
    std::regex space_regex;	
    std::string curr_dest, curr_comp, curr_jump;
	InstructionType type;
    std::unordered_map<std::string, uint16_t> lut;
    uint16_t curr_address;
	
 public:
	Parser(std::string filename);
	bool hasMoreLines();
	void advance();
	InstructionType instructionType() const;
	std::string getSymbol() const;
	std::string getDest() const;
	std::string getComp() const;
	std::string getJump() const;
    void parse(std::ofstream &fout, const Code &code);
};

std::ostream &operator<<(std::ostream &out, InstructionType it);
InstructionType parseInstruction(const std::string &s);
bool isNumeric(std::string s);
