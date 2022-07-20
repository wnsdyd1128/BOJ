#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 100
#define _CRT_SECURE_NO_DEPRECATE
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef tuple<int, int, int> tp;
typedef vector<tp> vtp;
ll dp[MAX_N + 1][21];
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;
	vi v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	dp[0][v[0]] = 1;
	
	for (int i = 1; i < N - 1; i++) {
		for (int j = 0; j + v[i] <= 20; j++)
			dp[i][j] += dp[i - 1][j + v[i]];
		for (int j = v[i]; j <= 20; j++)
			dp[i][j] += dp[i - 1][j - v[i]];
	}
	cout << dp[N - 2][v[N - 1]] << endl;
}