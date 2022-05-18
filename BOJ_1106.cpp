#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 1000
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int dp[MAX_N + 1]; // dp[i] := i 만큼 고객을 확보했을 때의 최소 비용
int N, C;
vii v;
int solution(int sum) {
	if (sum >= C)
		return 0;
	int& ret = dp[sum];
	if (ret != -1)
		return ret;
	for(int i = 0; i < N; i++) {
		auto [cost, customer] = v[i];
		if (ret == -1)
			ret = solution(sum + customer) + cost;
		else
			ret = min(ret, solution(sum + customer) + cost);
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> C >> N;
	v.resize(N + 1);
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < N; i++) {
		int cost, customer;
		cin >> cost >> customer;
		v[i] = make_pair(cost, customer);
	}
	cout << solution(0) << endl;
}