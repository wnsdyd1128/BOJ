#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	int length = s.length();
	int count = 1, blank = 0;
	for (int i = 0; i < length; i++) {
		if (isspace(s.at(i))) {
			if (i == 0 || i == length - 1) {
				blank++;
			}
			count++;
		}
	}
	count -= blank;
	if (s.length() == 1 && s[0] == ' ') {
		count--;
	}
	cout << count << endl;
}