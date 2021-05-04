#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	int count = 0;
	for (int i = 1; i <= n; i++) {
		string s = to_string(i);
		if (s.length() <= 2) {
			count++;
		}
		else if(s.length() == 3) {
			if (2 * s.at(1) == s.at(0) + s.at(2)) {
				count++;
			}
		}
	}
	cout << count;
}