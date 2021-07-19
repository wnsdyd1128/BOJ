#include <bits/stdc++.h>
#define endl '\n'
#define MOD 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 200
#define MAX_K 200
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
ll dp[MAX_N + 1][MAX_K + 1]; // dp[i][j] : i를 j개의 정수를 이용해 만드는 방법
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	dp[0][0] = 1;
	for (int i = 0; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			for (int s = 0; s <= i; s++) {
				dp[i][j] += dp[i - s][j - 1];
				dp[i][j] %= MOD;
			}
		}
	}
	cout << dp[N][K];
}