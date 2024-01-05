#include "parser.hh"
#include <regex>

Parser:: Parser(std::string filename) {
	file = std::ifstream{filename};
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

    if (temp.empty() && hasMoreLines()) {
        advance();
    }

	curr_line = temp;
	type = parseInstruction(curr_line);
    updateC();
}

InstructionType Parser:: parseInstruction(const std::string &s) const {
	if (s[0] == '@') {
		return InstructionType::A_INSTRUCTION;
	} else if ((curr_line[0] == '(') &&
						 (curr_line[curr_line.size() - 1] == ')')) {
		return InstructionType::L_INSTRUCTION;
	} else {
		return InstructionType::C_INSTRUCTION;
	}
}

InstructionType Parser:: instructionType() const {
	return type;
}

std::string Parser:: symbol() const {
  assert(type == A_INSTRUCTION || type == L_INSTRUCTION);
  if (type == A_INSTRUCTION) {
    return curr_line.substr(1);
  } else {
    return curr_line.substr(1, curr_line.size() - 2);
  }
}

std::string Parser:: dest() const {
  return curr_dest;
}


std::string Parser:: comp() const {
  return curr_comp;
}

std::string Parser:: jump() const {
  return curr_jump;
}

void Parser:: updateC() {
  size_t pos_eq = curr_line.find('=');
  size_t pos_sc = curr_line.find(';');

  curr_dest = "";
  curr_jump = "";

  if (pos_eq == std::string::npos && pos_sc == std::string::npos) {
    curr_comp = curr_line;
  } else if (pos_eq == std::string::npos){
    curr_comp = curr_line.substr(0, pos_sc);
    curr_jump = curr_line.substr(pos_sc + 1);
  } else if (pos_sc == std::string::npos) {
    curr_dest = curr_line.substr(0, pos_eq);
    curr_comp = curr_line.substr(pos_eq + 1);
  } else {
    curr_dest = curr_line.substr(0, pos_eq);
    curr_comp = curr_line.substr(pos_eq + 1, pos_sc - 2);
    curr_jump = curr_line.substr(pos_sc + 1);
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
