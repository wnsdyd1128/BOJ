#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_V 100000
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int dp[MAX_V + 1];
int N, K;
vi v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> K;
	v.resize(N + 1);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	dp[0] = 1;
	for(int i = 0; i < N; i++) {
		for (int j = v[i]; j <= K; j++)
			dp[j] += dp[j - v[i]];
	}
	cout << dp[K] << endl;
}