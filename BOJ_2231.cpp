#include <iostream>
#define INIT 9999999
using namespace std;

int main() {
	int n;
	cin >> n;
	int smallest = INIT;
	for (int i = 1; i <= n; i++) {
		int j = i;
		int initial = j;
		int sum = j;
		while (j != 0) {
			sum += j % 10;
			j /= 10;
		}
		if (sum == n) {
			smallest = min(initial, smallest);
		}
	}
	if (smallest == INIT) {
		cout << 0;
	}
	else {
		cout << smallest;
	}
	
}