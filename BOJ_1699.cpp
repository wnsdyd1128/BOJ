#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 100000
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int N;
int dp[MAX_N + 1];
//Top-Down
int solution(int n) {
	if (n == 0)
		return 0;
	int& ret = dp[n];
	if (ret != -1)
		return ret;
	for (int i = 1; i * i <= n; i++) {
		if (ret != -1) {
			ret = min(ret, 1 + solution(n - (i * i)));
		}
		else {
			ret = 1 + solution(n - (i * i));
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dp, -1, sizeof dp);
	cin >> N;
	cout << solution(N) << endl;


	// Bottom-Up
	/*dp[1] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j * j < i; j++) {
			if (dp[i] != -1) {
				dp[i] = min(dp[i], 1 + dp[i - (j * j)]);
			}
			else {
				dp[i] = 1 + dp[i - (j * j)];
			}
		}
	}
	cout << dp[N] << endl;*/
}