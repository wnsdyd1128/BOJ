#include <bits/stdc++.h>
#define endl '\n'
#define MAX_N 50000
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int dp[MAX_N + 1];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	memset(dp, -1, sizeof dp);
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j * j <= i; j++) {
			if (dp[i] != -1)
				dp[i] = min(dp[i], dp[i - (j * j)] + 1);
			else
				dp[i] = dp[i - (j * j)] + 1;
		}
	}
	cout << dp[n] << endl;
}