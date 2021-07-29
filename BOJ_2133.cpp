#include <bits/stdc++.h>
#define endl '\n'
#define MAX_N 30
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
ll dp[MAX_N + 1];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	dp[0] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = 3 * dp[i - 2];
		for (int j = i - 4; j >= 0; j -= 2) {
			dp[i] += 2 * dp[j];
		}
	}
	cout << dp[n] << endl;
}