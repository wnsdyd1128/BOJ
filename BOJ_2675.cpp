#include <iostream>
#include <string>
using namespace std;

int main() {
	int t, r;
	string s;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		string p;
		cin >> r;
		cin >> s;
		int length = s.length();
		for (int j = 0; j < length; j++) {
			for (int k = 0; k < r; k++) {
				p.push_back(s[j]);
			}
		}
		cout << p << endl;
	}
	
}