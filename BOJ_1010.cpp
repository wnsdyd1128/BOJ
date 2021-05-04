#include <iostream>
using namespace std;

long long int sum[30][30];
long long int c(int n, int r) {
	if (sum[n][r] != 0) return sum[n][r];
	if (n == r || r == 0) return 1;
	else {
		sum[n][r] = c(n - 1, r - 1) + c(n - 1, r);
		return sum[n][r];
	}
}
int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n, m;
		cin >> n >> m;
		long long int ans = c(m, n);
		cout << ans << endl;
	}
}