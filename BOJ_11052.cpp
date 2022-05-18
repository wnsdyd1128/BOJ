#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 1000
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vi v;
int dp[MAX_N + 1];
int N;
int solution(int n) {
	if (n == 0)
		return 0;
	int& ret = dp[n];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 1; i <= n; i++)
		ret = max(ret, solution(n - i) + v[i]);
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;
	v.resize(N + 1);
	memset(dp, -1, sizeof dp);
	for (int i = 1; i <= N; i++)
		cin >> v[i];
	cout << solution(N) << endl;
}