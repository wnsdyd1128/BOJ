#include <iostream>
#include <string>
#include <cstring>
#define MAX 101
#pragma warning(disable:4996)
using namespace std;

int check[26];
int main() {
	int t;
	int count = 0;
	string str;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> str;
		memset(check, 0, sizeof(int) * 26);
		bool flag = true;
		int length = str.length();
		for (int j = 0; j < length; j++) {
			if (check[str.at(j) - 'a'] != 0) {
				if (str.at(j - 1) != str.at(j)) {
					flag = false;
					break;
				}
			}
			check[str.at(j) - 'a']++;
		}
		if (flag) {
			count++;
		}
	}
	cout << count << endl;
}