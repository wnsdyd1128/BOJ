#include <bits/stdc++.h>
#define endl '\n'
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;

// 편집 거리 알고리즘
vector<vi> dp; // dp[i][j] : 두 문자열의 접두사 a[0...i] 와 ra[0...j]에 대한 최적의 점수

int score(char c1, char c2) {
	if (c1 == 'i') {
		if (c2 == 'i' || c2 == 'j' || c2 == 'l')
			return 0;
		else
			return 1;
	}
	else if (c1 == 'v') {
		if (c2 == 'v' || c2 == 'w')
			return 0;
		else
			return 1;
	}
	else
		return c1 == c2 ? 0 : 1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	string answer, right_answer;
	cin >> answer >> right_answer;
	dp.resize(n + 1);
	for (int i = 0; i <= n; i++) {
		dp[i].resize(m + 1);
	}
	for (int i = 1; i <= n; i++)
		dp[i][0] = i;
	for (int j = 1; j <= m; j++)
		dp[0][j] = j;
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = min({ dp[i - 1][j - 1] + score(answer[i - 1], right_answer[j - 1]), dp[i - 1][j] + 1, dp[i][j - 1] + 1 });
		}
	}
	cout << dp[n][m] << endl;
}