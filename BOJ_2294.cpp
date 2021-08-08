#include <bits/stdc++.h>
#define endl '\n'
#define MAX_V 100000
#define INF 10000
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int dp[MAX_V + 1];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	fill(dp, dp + MAX_V + 1, INF + 1);
	vi v;
	while (N--) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	dp[0] = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = v.at(i); j <= K; j++) {
			dp[j] = min(dp[j], 1 + dp[j - v.at(i)]);
		}
	}
	int ans = dp[K];
	if (ans == INF + 1)
		cout << -1 << endl;
	else
		cout << dp[K] << endl;
}