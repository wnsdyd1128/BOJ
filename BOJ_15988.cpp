#include <bits/stdc++.h>
#define endl '\n'
#define MOD 1000000009
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
ll dp[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC;
	cin >> TC;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	while (TC--) {
		int n;
		cin >> n;
		if (dp[n] != 0) {
			cout << dp[n] << endl;
		}
		else {
			for (int i = 4; i <= n; i++) {
				dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
				dp[i] %= MOD;
			}
			cout << dp[n] << endl;
		}
	}
}