#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MOD 10007
#define MAX_N 1000
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
	cin >> N;
	dp[2] = 3;
	dp[1] = 1;
	for (int i = 3; i <= N; i++)
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % MOD;
	cout << dp[N] << endl;
}