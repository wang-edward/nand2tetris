#include "parser.hh"
#include <regex>

Parser:: Parser(std::string filename)
    : file{filename}, space_regex{"\\s+"}, curr_address{Parser::START_ADDRESS} {
    lut = {
        {"R0",     0x00},
        {"R1",     0x01},
        {"R2",     0x02},
        {"R3",     0x03},
        {"R4",     0x04},
        {"R5",     0x05},
        {"R6",     0x06},
        {"R7",     0x07},
        {"R8",     0x08},
        {"R9",     0x09},
        {"R10",    0x0A},
        {"R11",    0x0B},
        {"R12",    0x0C},
        {"R13",    0x0D},
        {"R14",    0x0E},
        {"R15",    0x0F},
        {"SP",     0x00},
        {"LCL",    0x01},
        {"ARG",    0x02},
        {"THIS",   0x03},
        {"THAT",   0x04},
        {"SCREEN", 0x4000},
        {"KBD",    0x6000},
    };
}

bool Parser:: hasMoreLines() {
	return (file.peek() != EOF);
}

void Parser:: advance() {
	std::string temp;
    getline(file, temp);

    // remove spaces
    temp = regex_replace(temp, space_regex, "");
    // remove comments (if they exist)
    size_t comment_index = temp.find("//");
    if (comment_index != std::string::npos) {
        temp = temp.substr(0, comment_index);
    }

    // if line is whitespace, skip and call again
    if (temp.empty() && hasMoreLines()) {
        return advance();
    }

    // update state
	curr_line = temp;
	type = parseInstruction(curr_line);
    size_t pos_eq = curr_line.find('=');
    size_t pos_sc = curr_line.find(';');

    // set default values of instruction parts
    curr_dest = "";
    curr_jump = "";

    // new instruction contains only comp
    if (pos_eq == std::string::npos && pos_sc == std::string::npos) {
        curr_comp = curr_line;
    } else if (pos_eq == std::string::npos){
        // comp and jump
        curr_comp = curr_line.substr(0, pos_sc);
        curr_jump = curr_line.substr(pos_sc + 1);
    } else if (pos_sc == std::string::npos) {
        // comp and dest
        curr_dest = curr_line.substr(0, pos_eq);
        curr_comp = curr_line.substr(pos_eq + 1);
    } else {
        // all 3
        curr_dest = curr_line.substr(0, pos_eq);
        curr_comp = curr_line.substr(pos_eq + 1, pos_sc - 2);
        curr_jump = curr_line.substr(pos_sc + 1);
    }
}

InstructionType Parser:: instructionType() const {
	return type;
}

std::string Parser:: getSymbol() const {
    switch (type) {
        case InstructionType::C_INSTRUCTION:
            throw std::runtime_error{"symbol() can only be called when the current instruction is an A or L instruction."};
        break;
        case InstructionType::A_INSTRUCTION:
            // return line without leading @
            return curr_line.substr(1); 
        break;
        case InstructionType::L_INSTRUCTION:
            // remove front and back parentheses
            return curr_line.substr(1, curr_line.size() - 2); 
        break;
    }
}

std::string Parser:: getDest() const {
  return curr_dest;
}

std::string Parser:: getComp() const {
  return curr_comp;
}

std::string Parser:: getJump() const {
  return curr_jump;
}

void Parser:: parse(std::ofstream &fout, const Code &code) {
    // generate lookup table
    file.seekg(0, std::ios::beg);
    while (hasMoreLines()) {
        advance();
        if (instructionType() == InstructionType::L_INSTRUCTION) {
            // TODO: add proper line number for better error messages
            // check for duplicate labels
            std::string label = getSymbol();
            auto it = lut.find(label);
            if (it != lut.end()) {
                throw std::runtime_error{"error: duplicate label: " + label + " at address: " + 
                                        std::to_string(it->second) + " and " + 
                                        std::to_string(curr_address)}; // TODO better error message
            }
            lut[getSymbol()] = curr_address;
        } else {
            // don't increment address when an L_instruction is read
            curr_address++;
        }
        if (curr_address >= Parser::END_ADDRESS) {
            throw std::runtime_error{"address overflow: program has too many lines"};
        }
    }

    // parse
    file.seekg(0, std::ios::beg);
    curr_address = Parser::START_ADDRESS;
    while (hasMoreLines()) {
        advance();
        switch (instructionType()) {
            case InstructionType::C_INSTRUCTION:
                fout << "111"; // indicate C instruction
                fout << code.convertComp(getComp());
                fout << code.convertDest(getDest());
                fout << code.convertJump(getJump()) << std::endl;
                break;
            case InstructionType::A_INSTRUCTION: {
                // int address = getSymbol();
                std::string label = getSymbol();

                uint16_t numeral = -1;
                if (isNumeric(label)) {
                    numeral = stoi(label);
                } else {
                    if (lut.find(label) == lut.end()) {
                        lut[label] = curr_address;
                        curr_address++;
                    }
                    numeral = lut.at(label);
                }
                std::string binary = std::bitset<16>(numeral).to_string();
                fout << binary << std::endl;
                break;
            }
            case InstructionType::L_INSTRUCTION:
                // do nothing
                break;
        }
        curr_address++;
    }
}

std::ostream &operator<<(std::ostream &out, InstructionType it) {
	switch (it) {
		case C_INSTRUCTION:
			out << "C_INSTRUCTION";
			break;
		case A_INSTRUCTION:
			out << "A_INSTRUCTION";
			break;
		case L_INSTRUCTION:
			out << "L_INSTRUCTION";
			break;
	}
	return out;
}

InstructionType parseInstruction(const std::string &s) {
	if (s.front() == '@') {
		return InstructionType::A_INSTRUCTION;
	} else if (s.front() == '(' && s.back() == ')') {
		return InstructionType::L_INSTRUCTION;
	} else {
		return InstructionType::C_INSTRUCTION;
	}
}

bool isNumeric(std::string s) {
    auto it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
