#include <bits/stdc++.h>
#define endl '\n'
#define MAX_N 100000
#define MOD 1000000009
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
uint64_t dp[MAX_N + 1][4];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = dp[3][2] = dp[3][3] = 1;
	int TC;
	cin >> TC;
	while (TC--) {
		int n;
		cin >> n;
		for (int i = 4; i <= n; i++) {
			dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
			dp[i][2] = (dp[i - 2][3] + dp[i - 2][1]) % MOD;
			dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;
		}
		cout << (dp[n][1] + dp[n][2] + dp[n][3]) % MOD << endl;
	}
}