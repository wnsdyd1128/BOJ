#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 100000
#define _CRT_SECURE_NO_DEPRECATE
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int N;
//int grid[MAX_N + 1][3];
//int dp[MAX_N + 1][3];
//int solution(int depth, int pos) {
//	if (depth == N)
//		return 0;
//	int& ret = dp[depth][pos];
//	if (ret != 0)
//		return ret;
//	if (pos == 0)
//		return ret = max(solution(depth + 1, pos), solution(depth + 1, pos + 1)) + grid[depth][pos];
//	if (pos == 1)
//		return ret = max({ solution(depth + 1, pos), solution(depth + 1, pos - 1), solution(depth + 1, pos + 1) }) + grid[depth][pos];
//	if (pos == 2)
//		return ret = max(solution(depth + 1, pos), solution(depth + 1, pos - 1)) + grid[depth][pos];
//}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	ii dp[2][3]; // first -> max, second -> min
	int grid[3];
	cin >> grid[0] >> grid[1] >> grid[2];
	for (int i = 0; i < 3; i++) {
		dp[0][i].first = dp[0][i].second = grid[i];
	}
	for (int i = 1; i < N; i++) {
		cin >> grid[0] >> grid[1] >> grid[2];
		dp[1][0].first = max(dp[0][0].first, dp[0][1].first) + grid[0];
		dp[1][0].second = min(dp[0][0].second, dp[0][1].second) + grid[0];
		dp[1][1].first = max({ dp[0][0].first, dp[0][1].first, dp[0][2].first }) + grid[1];
		dp[1][1].second = min({ dp[0][0].second, dp[0][1].second, dp[0][2].second }) + grid[1];
		dp[1][2].first = max(dp[0][1].first, dp[0][2].first) + grid[2];
		dp[1][2].second = min(dp[0][1].second, dp[0][2].second) + grid[2];
		for (int j = 0; j < 3; j++) {
			dp[0][j].first = dp[1][j].first;
			dp[0][j].second = dp[1][j].second;
		}
	}
	int maxAns = 0;
	int minAns = INF;
	for (int i = 0; i < 3; i++) {
		maxAns = max(maxAns, dp[0][i].first);
		minAns = min(minAns, dp[0][i].second);
	}
	cout << maxAns << ' ' << minAns << endl;
}