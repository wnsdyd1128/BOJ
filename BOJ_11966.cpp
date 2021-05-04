#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	if ((int)log2(n) - log2(n) == 0) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}