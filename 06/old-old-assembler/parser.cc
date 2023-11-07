module Parser;

using namespace std;

Parser:: Parser(string file): file{ifstream{file}} {}

bool Parser:: hasMoreLines() {
	return (this->file.peek() != EOF);
}

void Parser:: advance() {
	// skip newlines
	string temp;
	if (this->hasMoreLines()) {
		getline(file, temp);
		while (temp == "" && (temp[0] == '/')) {
			getline(file, temp);
		}
	}
	// get rid of comments
	string ans;
	for (char c : temp) {
		if (c == '/') {
			break;
		} else {
			ans += c;
		}
	}
	this->curr_line = ans;
}

InstructionType Parser:: instructionType() {
	if (curr_line[0] == '@') {
		return InstructionType::A_INSTRUCTION;
	} else if ((curr_line[0] == '(') &&
						 (curr_line[curr_line.size() - 1] == ')')) {
		return InstructionType::L_INSTRUCTION;
	} else {
		return InstructionType::C_INSTRUCTION;
	}
}

string Parser:: symbol() {
	if (




