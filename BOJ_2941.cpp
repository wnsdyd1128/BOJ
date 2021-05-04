#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int count = 0;
	int length = str.length();
	for (int i = 0; i < length; i++) {
		if (i + 1 < length) {
			switch (str.at(i)) {
			case 'c':
				if ((str.at(i + 1) == '=' || str.at(i + 1) == '-')) {
					i++;
				}
				count++;
				break;
			case 'd':
				if (str.at(i + 1) == '-') {
					i++;
				}
				else if (str.at(i + 1) == 'z') {
					if (i + 2 < length && str.at(i + 2) == '=') {
						i += 2;
					}
				}
				count++;
				break;
			case 'l':
				if (str.at(i + 1) == 'j') {
					i++;
				}
				count++;
				break;
			case 'n':
				if (str.at(i + 1) == 'j') {
					i++;
				}
				count++;
				break;
			case 's':
			case 'z':
				if (str.at(i + 1) == '=') {
					i++;
				}
				count++;
				break;
			default:
				count++;
				break;
			}
		}
		else if (i + 1 == length) {
			count++;
		}
	}
	cout << count;
}