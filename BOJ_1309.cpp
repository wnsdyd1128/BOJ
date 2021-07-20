#include <bits/stdc++.h>
#define endl '\n'
#define MOD 9901
#define MAX_N 100000
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int dp[MAX_N + 1][3];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	dp[1][0] = dp[1][1] = dp[1][2] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
		dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
		dp[i][2] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][0] %= MOD;
		dp[i][1] %= MOD;
		dp[i][2] %= MOD;
	}
	cout << (dp[n][0] + dp[n][1] + dp[n][2]) % MOD << endl;
}