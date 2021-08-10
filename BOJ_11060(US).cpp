#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000
#define MAX_N 10000
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int dp[MAX_N + 1];
vi v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fill(dp, dp + MAX_N + 1, INF);
	dp[0] = 0;
	int N;
	cin >> N;
	while (N--) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	for (int i = 0; i < v.size(); i++) {
		int jump = v.at(i);
		for (int j = 1; j <= jump; j++) {
			dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}

	if (dp[v.size() - 1] == INF)
		cout << "-1" << endl;
	else
		cout << dp[v.size() - 1] << endl;
}