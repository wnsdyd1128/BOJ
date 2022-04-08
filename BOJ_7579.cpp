#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 100
#define MAX_C 10000
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
vii v;
int N, M;
int dp[MAX_N + 1][MAX_C + 1]; // dp[i + 1][j] := i번째까지 비용 j를 소모했을 때 확보한 메모리 공간
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> M;
	v.resize(N);
	memset(dp, 0, sizeof dp);
	for (int i = 0; i < N; i++)
		cin >> v[i].first; // first := memory
	for (int i = 0; i < N; i++)
		cin >> v[i].second; // second := cost
	for(int i = 0; i < N; i++) {
		for(int j = 0; j <= MAX_C; j++) {
			if (j - v[i].second < 0)
				dp[i + 1][j] = dp[i][j];
			else
				dp[i + 1][j] = max(dp[i][j], dp[i][j - v[i].second] + v[i].first);
		}
	}
	int ans = 0;
	for(int i = MAX_C; i >= 0; i--) {
		if (dp[N][i] >= M)
			ans = i;
	}
	cout << ans << endl;
}