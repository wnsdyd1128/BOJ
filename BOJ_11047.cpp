#include <iostream>
using namespace std;

int main() {
	int n, k;
	int count = 0;
	cin >> n >> k;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		if ((k / arr[i]) != 0) {
			count += k / arr[i];
			k -= k / arr[i] * arr[i];
		}
	}
	cout << count;
}