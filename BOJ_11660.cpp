#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 1024
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
int matrix[MAX_N + 1][MAX_N + 1];
int dp[MAX_N + 1][MAX_N + 1];
int N, M;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> matrix[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + matrix[i][j] - dp[i - 1][j - 1];
		}
	}
	while (M--) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] << endl;
	}
}