#include "code.hh"

using namespace std;

string Code:: convert(const map<string, string> &m, const string &s) const {
  auto it = m.find(s);
  if (it != m.end()) {
    return it->second;
  } else {
    throw std::runtime_error{"invalid command: " + s};
  }
}

string Code:: dest(const string &s) const {
  return convert(map_dest, s);
}

string Code:: comp(const string &s) const {
  return convert(map_comp, s);
}

string Code:: jump(const string &s) const {
  return convert(map_jump, s);
}

Code:: Code() {
  // map_dest
  map_dest.insert({"", ""}); // empty case
  map_dest.insert({"null", "000"});
  map_dest.insert({"M",   "001"});
  map_dest.insert({"D",   "010"});
  map_dest.insert({"MD",  "011"}); // in the book it's DM ?
  map_dest.insert({"A",   "100"});
  map_dest.insert({"AM",  "101"});
  map_dest.insert({"AD",  "110"});
  map_dest.insert({"AMD", "111"}); // in the book its ADM?

  // map_comp, a = 0
  map_comp.insert({"", ""}); // empty case
  map_comp.insert({"0",   "0101010"});
  map_comp.insert({"1",   "0111111"});
  map_comp.insert({"-1",  "0111010"});
  map_comp.insert({"D",   "0001100"});
  map_comp.insert({"A",   "0110000"});
  map_comp.insert({"!D",  "0001101"});
  map_comp.insert({"!A",  "0110001"});
  map_comp.insert({"-D",  "0001111"});
  map_comp.insert({"-A",  "0110011"});
  map_comp.insert({"D+1", "0011111"});
  map_comp.insert({"A+1", "0110111"});
  map_comp.insert({"D-1", "0001110"});
  map_comp.insert({"A-1", "0110010"});
  map_comp.insert({"D+A", "0000010"});
  map_comp.insert({"D-A", "0010011"});
  map_comp.insert({"A-D", "0000111"});
  map_comp.insert({"D&A", "0000000"});
  map_comp.insert({"D|A", "0010101"});

  // map_comp, a = 1
  map_comp.insert({"M",   "1110000"});
  map_comp.insert({"!M",  "1110001"});
  map_comp.insert({"-M",  "111011"});
  map_comp.insert({"M+1", "1110111"});
  map_comp.insert({"M-1", "1110010"});
  map_comp.insert({"D+M", "1000010"});
  map_comp.insert({"D-M", "1010011"});
  map_comp.insert({"M-D", "1000111"});
  map_comp.insert({"D&M", "1000000"});
  map_comp.insert({"D|M", "1010101"});

  // map_jump 
  map_jump.insert({"", ""});
  map_jump.insert({"null", "000"});
  map_jump.insert({"JGT", "001"});
  map_jump.insert({"JEQ", "010"});
  map_jump.insert({"JGE", "011"});
  map_jump.insert({"JLT", "100"});
  map_jump.insert({"JNE", "101"});
  map_jump.insert({"JLE", "110"});
  map_jump.insert({"JMP", "111"});
}
