#include <bits/stdc++.h>
#define endl '\n'
#define MAX_N 1000
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int dp[MAX_N + 1];

int solution(int n, vi v) {
	if (n == 0)
		return 0;
	int& ret = dp[n];
	if (ret != -1)
		return ret;
	for (int i = 1; i <= n; i++) {
		ret = max(ret, solution(n - i, v) + v.at(i));
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dp, -1, sizeof dp);
	int N;
	cin >> N;
	vi v(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> v.at(i);
	}
	/*for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + v.at(j));
		}
	}*/
	cout << solution(N, v);
}