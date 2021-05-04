#include <iostream>
#include <string>
int cnt[26];
using namespace std;

int main() {
	string s;
	cin >> s;
	int length = s.length();
	for (int i = 0; i < length; i++) {
		if (s.at(i) >= 65 && s.at(i) <= 90) {
			s.at(i) += 32;
		}
		cnt[s.at(i) - 'a']++;

	}
	int max = 0;
	int index;
	bool flag = false;
	for (int i = 0; i < 26; i++) {
		if (max < cnt[i]) {
			max = cnt[i];
			index = i + 'A';
			if (flag) {
				flag = false;
			}
		}
		else if (max > cnt[i]) {}
		else {
			flag = true;
		}
	}
	if (flag) {
		cout << "?" << endl;
	}
	else {
		cout << (char)index << endl;
	}
}