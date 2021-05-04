#include <iostream>
#include <string>
#include <cstring>
using namespace std;
//ascii a : 97

int arr[26];
int main() {
	memset(arr, -1, sizeof(int) * 26);
	string s;
	cin >> s;
	int index;
	for (int i = 0; i < s.length(); i++) {
		index = s.at(i) - 'a';
		if (arr[index] == -1) {
			arr[index] = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		cout << arr[i] << " ";
	}
}