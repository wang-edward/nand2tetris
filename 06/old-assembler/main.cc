import Parser;
import <iostream>

int main() {
	Parser p{test.txt};
	while (p.hasMoreLines()) {
		cout << p.curr_line << endl;
		p.advance();
	}
}

