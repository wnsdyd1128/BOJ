#include <bits/stdc++.h>
#define endl '\n'
#define MAX_N 100000
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
	int n, m;
	cin >> n >> m;
	vi v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i < v.size(); i++) {
		dp[i] = dp[i - 1] + v[i];
	}
	while (m--) {
		int i, j;
		cin >> i >> j;
		cout << dp[j] - dp[i - 1] << endl;
	}
}