#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int time = 0;
	int length = s.length();
	for (int i = 0; i < length; i++) {
		if (s[i] <= 'C') {
			time += 3;
		}
		else if (s[i] <= 'F') {
			time += 4;
		}
		else if (s[i] <= 'I') {
			time += 5;
		}
		else if (s[i] <= 'L') {
			time += 6;
		}
		else if (s[i] <= 'O') {
			time += 7;
		}
		else if (s[i] <= 'S') {
			time += 8;
		}
		else if (s[i] <= 'V') {
			time += 9;
		}
		else {
			time += 10;
		}
	}
	cout << time;
}