#include <iostream>
using namespace std;

int main() {

  string curr_line = "D=A";
  string curr_dest;
  string curr_comp;
  string curr_jump;

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

  cout << curr_dest << endl;
  cout << curr_comp << endl;
  cout << curr_jump << endl;

}
