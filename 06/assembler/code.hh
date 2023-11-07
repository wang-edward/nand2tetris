#include <map>
#include <string>
#include <iostream>

using namespace std;

class Code {
private:
  map<string, string> map_dest;
  map<string, string> map_comp;
  map<string, string> map_jump;
  string convert(const map<string, string> &m, const string &s) const;
public:
  explicit Code();
  string dest(const string &s) const;
  string comp(const string &s) const;
  string jump(const string &s) const;
};
