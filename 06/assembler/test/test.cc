#include <iostream>
#include <fstream>

using namespace std;

int main() {
    fstream fin{"words.txt"};
    string x;
    while (getline(fin, x)) {
        cout << "{" << x << "}";
        if (x.empty()) cout << " empty";
        cout << endl;
    }
}
