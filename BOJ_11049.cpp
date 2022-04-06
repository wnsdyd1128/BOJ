#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 500
#define MOD (int)(1e9+7)  // NOLINT(clang-diagnostic-unused-macros)
#define _CRT_SECURE_NO_DEPRECATE  // NOLINT(clang-diagnostic-reserved-macro-identifier)
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS  // NOLINT(clang-diagnostic-reserved-macro-identifier)
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int dp[MAX_N + 1][MAX_N + 1];
vii v;
int solution(int i, int j) {
	if (i == j)
		return 0;
	int& ret = dp[i][j];
	if (ret != -1)
		return ret;
	for(int k = i; k + 1 <= j; k++) {
		int sum = v[i].first * v[k + 1].first * v[j].second;
		int ans = solution(i, k) + solution(k + 1, j) + sum; // dp[i][j] := 행렬 i~j까지의 최소한의 연산
		if (ret == -1 || ret > ans)
			ret = ans;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	cin >> N;
	v.resize(N + 1);
	memset(dp, -1, sizeof dp);
	for(int i = 1; i <= N; i++) {
		cin >> v[i].first >> v[i].second;
	}
	cout << solution(1, N) << endl;
}