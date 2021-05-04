#include <iostream>
#include <cstring>
#define MAX_LEN 101
#pragma warning(disable:4996)
using namespace std;

char* strreverse(char* str) {
	char* p1, * p2;
	if (!str || !*str)
		return str;
	for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
	{
		*p1 ^= *p2;
		*p2 ^= *p1;
		*p1 ^= *p2;
	}
	return str;
}
int main() {
	char arr[MAX_LEN];
	cin >> arr;
	char* ptr = new char[strlen(arr) + 1];
	strcpy(ptr, arr);
	strreverse(ptr);
	if (strcmp(ptr, arr) == 0) {
		cout << "1" << endl;
	}
	else {
		cout << "0" << endl;
	}
}