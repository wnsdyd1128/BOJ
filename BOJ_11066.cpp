#include <bits/stdc++.h>
#define endl '\n'
#define MAX_K 500
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int dp[MAX_K + 1][MAX_K + 1];
vi v;
int solution(int i, int j) {
	if (i == j)
		return 0;
	int& ret = dp[i][j];
	if (ret != -1)
		return ret;
	int sum = 0;
	for (int k = i; k <= j; k++) {
		sum += v[k];
	}
	for (int k = i; k + 1 <= j; k++) {
		int ans = solution(i, k) + solution(k + 1, j) + sum;
		if (ret == -1 || ret > ans)
			ret = ans;
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC;
	cin >> TC;
	v.resize(MAX_K + 1);
	while (TC--) {
		int n;
		cin >> n;
		memset(dp, -1, sizeof dp);
		for (int i = 1; i <= n; i++) {
			cin >> v[i];
		}
		cout << solution(1, n) << endl;
	}
}