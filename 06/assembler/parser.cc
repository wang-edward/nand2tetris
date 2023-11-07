#include "parser.hh"
#include <regex>
#include <assert.h>

using namespace std;

Parser:: Parser(string filename) {
	file = ifstream{filename};
}

bool Parser:: hasMoreLines() {
	return (file.peek() != EOF);
}

void Parser:: advance() {
	// skip newlines
	string temp;
	if (hasMoreLines()) {
		getline(file, temp);
		while ((temp == "" || (temp[0] == '/')) && hasMoreLines()) {
			getline(file, temp);
		}
	}

	// remove whitespace
	regex space_regex{"\\s+"};	
	temp = regex_replace(temp, space_regex, "");
	
	// get rid of comments
	string ans;
	for (char c : temp) {
		if (c == '/') {
			break;
		} else {
			ans += c;
		}
	}
	curr_line = ans;
	type = parseInstruction(curr_line);
  updateC();
}

InstructionType Parser:: parseInstruction(const string &s) const {
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

string Parser:: symbol() const {
  assert(type == A_INSTRUCTION || type == L_INSTRUCTION);
  if (type == A_INSTRUCTION) {
    return curr_line.substr(1);
  } else {
    return curr_line.substr(1, curr_line.size() - 2);
  }
}

string Parser:: dest() const {
  return curr_dest;
}


string Parser:: comp() const {
  return curr_comp;
}

string Parser:: jump() const {
  return curr_jump;
}

void Parser:: updateC() {
  size_t pos_eq = curr_line.find('=');
  size_t pos_sc = curr_line.find(';');

  curr_dest = "";
  curr_jump = "";

  if (pos_eq == string::npos && pos_sc == string::npos) {
    // cout << "!eq, !sc" << endl;
    curr_comp = curr_line;
  } else if (pos_eq == string::npos){
    // cout << "!eq" << endl;
    curr_comp = curr_line.substr(0, pos_sc);
    curr_jump = curr_line.substr(pos_sc + 1);
  } else if (pos_sc == string::npos) {
    // cout << "!sc" << endl;
    curr_dest = curr_line.substr(0, pos_eq);
    curr_comp = curr_line.substr(pos_eq + 1);
  } else {
    // cout << "none" << endl;
    curr_dest = curr_line.substr(0, pos_eq);
    curr_comp = curr_line.substr(pos_eq + 1, pos_sc - 2);
    curr_jump = curr_line.substr(pos_sc + 1);
  }
}

ostream &operator<<(ostream &out, InstructionType it) {
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
