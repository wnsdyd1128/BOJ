#include <bits/stdc++.h>
#define endl '\n'
#define MAX_N 100000
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int dp[MAX_N + 1];
int dpr[MAX_N + 1];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vi v;
	int N;
	cin >> N;
	while (N--) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	for (int i = 0; i < v.size(); i++) {
		dp[i] = v.at(i);
		if (i == 0)
			continue;
		dp[i] = max(dp[i], dp[i - 1] + v.at(i));
	}
	for (int j = v.size() - 1; j >= 0; j--) {
		dpr[j] = v.at(j);
		if (j == v.size() - 1)
			continue;
		dpr[j] = max(dpr[j], dpr[j + 1] + v.at(j));
	}
	int ans = dp[0];
	for (int i = 1; i < v.size(); i++) {
		ans = max(ans, dp[i]);
	}
	for (int i = 1; i < v.size() - 1; i++) {
		ans = max(ans, dp[i - 1] + dpr[i + 1]);
	}
	cout << ans << endl;
}