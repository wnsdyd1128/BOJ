#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 300
#define _CRT_SECURE_NO_DEPRECATE
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
//int solution2(int cur, int cnt, int* score) {
//	if (cur < 0)
//		return 0;
//	int& ret = dp[cur][cnt];
//	if (ret != 0)
//		return ret;
//	if (cnt == 0) {
//		return ret = max(solution2(cur - 1, 1, score), solution2(cur - 2, 0, score)) + score[cur];
//	}
//	else {
//		return ret = solution2(cur - 2, 0, score) + score[cur];
//	}
//}
int N;
vi v;
int dp[MAX_N + 1][2]; // dp[i][j] := i - 1번째 까지 계단을 연속 j번 밟아 i에 있을 때 dp
int solution(int idx, int continuity) {
	if (idx >= N)
		return -INF;
	if (idx == N - 1)
		return 0;
	int& ret = dp[idx][continuity];
	if (ret != 0)
		return ret;
	if (continuity == 0)
		return ret = max(solution(idx - 1, 1), solution(idx - 2, 0)) + v[idx];
	else
		return ret = solution(idx - 2, 0) + v[idx];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	cout << solution(0, 0);
}