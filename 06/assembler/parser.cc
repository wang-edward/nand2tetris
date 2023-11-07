#include "parser.hh"
#include <assert.h>

using namespace std;

Parser:: Parser(string filename): im{}{
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
  cout << "curr_dest: " << curr_dest << endl;
  cout << "curr_comp: " << curr_comp << endl;
  cout << "curr_jump: " << curr_jump << endl;
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
  // cout << "curr_dest: " << curr_dest << endl;
  return convert(im.dest, curr_dest);
}


string Parser:: comp() const {

  for (auto x : im.comp) {
    cout << "[" << x.first << ", " << x.second << "]" << endl;
  }

  cout << "_-------------------------" << endl;

  cout << "curr_comp: [" << curr_comp  << "]"<< endl;
  auto it = im.comp.find(curr_comp);
  if (it != im.comp.end()) {
    return it->second;
  } else {
    cerr << "NOT FOUND" << endl;
    exit(123);
  }
  // return convert(im.comp, curr_comp);
}

string Parser:: jump() const {
  // cout << "curr_jump: " << curr_jump << endl;
  return convert(im.jump, curr_jump);
}

void Parser:: updateC() {
  size_t pos_eq = curr_line.find('=');
  size_t pos_sc = curr_line.find(';');

  curr_dest = "";
  curr_jump = "";

  if (pos_eq == string::npos && pos_sc == string::npos) {
    cout << "!eq, !sc" << endl;
    curr_comp = curr_line;
  } else if (pos_eq == string::npos){
    cout << "!eq" << endl;
    curr_comp = curr_line.substr(0, pos_sc);
    curr_jump = curr_line.substr(pos_sc + 1);
  } else if (pos_sc == string::npos) {
    cout << "!sc" << endl;
    curr_dest = curr_line.substr(0, pos_eq);
    curr_comp = curr_line.substr(pos_eq + 1);
  } else {
    cout << "none" << endl;
    curr_dest = curr_line.substr(0, pos_eq);
    curr_comp = curr_line.substr(pos_eq + 1, pos_sc - 2);
    curr_jump = curr_line.substr(pos_sc + 1);
  }
}

string Parser:: convert(const map<string, string> &m, string s) const {
  assert(type == C_INSTRUCTION);
  auto it = m.find(s);
  if (it != m.end()) {
    return it->second;
  } else {
    cout << "[" << it->first << ", " << it->second << "]" << endl;
    cerr << "invalid command: " << s << endl;
    exit(123);
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

InstructionMapping:: InstructionMapping() {
  // dest
  dest.insert({"", ""}); // empty case
  dest.insert({"null", "000"});
  dest.insert({"M",   "001"});
  dest.insert({"D",   "010"});
  dest.insert({"DM",  "011"});
  dest.insert({"A",   "100"});
  dest.insert({"AM",  "101"});
  dest.insert({"AD",  "110"});
  dest.insert({"ADM", "111"});

  // comp, a = 0
  comp.insert({"", ""}); // empty case
  comp.insert({"0",   "0101010"});
  comp.insert({"1",   "0111111"});
  comp.insert({"-1",  "0111010"});
  comp.insert({"D",   "0001100"});
  comp.insert({"A",   "0110000"});
  comp.insert({"!D",  "0001101"});
  comp.insert({"!A",  "0110001"});
  comp.insert({"-D",  "0001111"});
  comp.insert({"-A",  "0110011"});
  comp.insert({"D+1", "0011111"});
  comp.insert({"A+1", "0110111"});
  comp.insert({"D-1", "0001110"});
  comp.insert({"A-1", "0110010"});
  comp.insert({"D+A", "0000010"});
  comp.insert({"D-A", "0010011"});
  comp.insert({"A-D", "0000111"});
  comp.insert({"D&A", "0000000"});
  comp.insert({"D|A", "0010101"});

  // comp, a = 1
  comp.insert({"M",   "1110000"});
  comp.insert({"!M",  "1110001"});
  comp.insert({"-M",  "111011"});
  comp.insert({"M+1", "1110111"});
  comp.insert({"M-1", "1110010"});
  comp.insert({"D+M", "1000010"});
  comp.insert({"D-M", "1010011"});
  comp.insert({"M-D", "1000111"});
  comp.insert({"D&M", "1000000"});
  comp.insert({"D|M", "1010101"});

  // jump 
  jump.insert({"", ""});
  jump.insert({"null", "000"});
  jump.insert({"JGT", "001"});
  jump.insert({"JEQ", "010"});
  jump.insert({"JGE", "011"});
  jump.insert({"JLT", "100"});
  jump.insert({"JNE", "101"});
  jump.insert({"JLE", "110"});
  jump.insert({"JMP", "111"});
}

