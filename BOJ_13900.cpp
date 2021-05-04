#include <iostream>
using namespace std;

int main() {
	long long int n, sum = 0;
	cin >> n;
	long long int ans = 0;
	long long int* arr = new long long int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	for (int i = 0; i < n; i++) {
		sum -= arr[i];
		ans += sum * arr[i];
	}
	cout << ans;
}