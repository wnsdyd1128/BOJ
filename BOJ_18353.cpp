#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000
#define MAX_N 2000
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
	int N;
	vi v;
	cin >> N;
	fill(dp, dp + N, INF);
	while (N--) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i ++) {
		*lower_bound(dp, dp + v.size(), v[i]) = v[i];
	}
	int ans = v.size() - (lower_bound(dp, dp + v.size(), INF) - dp);
	cout << ans << endl;
}