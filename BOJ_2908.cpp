#include <iostream>
#include <cstring>
using namespace std;
void strreverse(char* str){
	char* p1, * p2;
	if (!str || !*str)
		return;
	for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
	{
		*p1 ^= *p2;
		*p2 ^= *p1;
		*p1 ^= *p2;
	}
}
int main() {
	char a[4];
	char b[4];
	cin >> a >> b;
	strreverse(a);
	strreverse(b);
	if (strcmp(a, b) > 0) {
		cout << a;
	}
	else {
		cout << b;
	}
}