#include <bits/stdc++.h>
#define endl '\n'
#define MAX_N 1000
#define INF 1e7
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int N;
int dp[MAX_N + 1];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	fill(dp, dp + N + 1, INF);
	vi v(N + 1);
	for (int i = 1; i <= N; i++) {
		int cost;
		cin >> cost;
		v.at(i) = cost;
	}
	dp[0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j] + v.at(j));
		}
	}
	cout << dp[N] << endl;
}