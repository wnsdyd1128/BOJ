#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 30
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
ll dp[MAX_N + 1];
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	cin >> N;
	for (int i = 3; i <= N; i++) {
		dp[i] = 3 * dp[i - 2];
		for (int j = i - 4; j >= 0; j -= 2)
			dp[i] += 2 * dp[j];
	}
	cout << dp[N] << endl;
}