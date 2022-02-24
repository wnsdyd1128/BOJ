#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 50
#define MAX_M 1000
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
int N, S, M;
int dp[MAX_N + 1][MAX_M + 1];
vi v;
int solution(int idx, int sum) { // -1 -> 탐색 전, -INF -> 불가능
	// dp[idx][sum] : idx에서 현재 볼륨이 sum일 때의 가능한 최대 볼륨
	if (sum < 0 || sum > M)
		return -INF;
	if (idx == N)
		return sum;
	int& ret = dp[idx][sum];
	if (ret != -1)
		return ret;
	return ret = max(solution(idx + 1, sum + v[idx]), solution(idx + 1, sum - v[idx]));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dp, -1, sizeof dp);
	cin >> N >> S >> M;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	int ans = solution(0, S);
	if (ans == -INF)
		cout << -1 << endl;
	else
		cout << ans << endl;
}