#include <iostream>
#pragma warning(disable:4996)
using namespace std;

int main() {
	int n;
	int sum = 0;
	cin >> n;
	char arr[101];
	cin >> arr;
	char* s = new char[n + 1];
	strcpy(s, arr);
	for (int i = 0; i < strlen(s); i++) {
		sum += s[i] - '0';
	}
	cout << sum;
}