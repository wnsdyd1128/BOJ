#include <iostream>
using namespace std;


int T(int n) {
	return n * (n + 1) / 2;
}
int findMax(int n) {
	int i = 1;
	while (true) {
		if (T(i) <= n && n <= T(i + 1) ) {
			break;
		}
		i++;
	}
	return i;
}
int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n;
		bool flag = false;
		cin >> n;
		int max = findMax(n);
		for (int i = 1; i <= max; i++) {
			for (int j = 1; j <= max; j++) {
				for (int k = 1; k <= max; k++) {
					int sum = T(i) + T(j) + T(k);
					if (sum == n) {
						flag = true;
						break;
					}
				}
			}
		}
		if (flag) {
			cout << "1" << endl;
		}
		else {
			cout << "0" << endl;
		}
	}
}