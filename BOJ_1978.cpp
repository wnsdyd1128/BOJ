#include <iostream>
#define endl '\n'
using namespace std;

int prime[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	prime[1] = 1;
	int n, count = 0;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 2; i <= 1000; i++) {
		if (prime[i] != 0) {
			continue;
		}
		else {
			for (int j = i * i; j <= 1000; j += i) {
				prime[j]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (prime[arr[i]] == 0) {
			count++;
		}
	}
	cout << count << endl;
}