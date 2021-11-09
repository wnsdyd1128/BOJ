#include <bits/stdc++.h>
#define endl '\n'
#define MAX_N 100
#define INF int(1e9)
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int dp[MAX_N + 1];
bool compare(ii a, ii b) {
	return a.first < b.first;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vii v;
	int n;
	cin >> n;
	fill(dp, dp + n, INF);
	while (n--) {
		int a, b;
		cin >> a >> b; // a to b
		v.push_back({ a, b });
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		*lower_bound(dp, dp + v.size(), v[i].second) = v[i].second;
	}
	int ans = v.size() - (lower_bound(dp, dp + v.size(), INF) - dp);
	cout << ans << endl;
}