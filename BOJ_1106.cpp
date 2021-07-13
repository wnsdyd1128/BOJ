#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;

int dp[21][1001];
int C, N;
vii v;
int solution(int idx, int sum) {
	if (sum >= C) {
		return 0;
	}
	int& ret = dp[idx][sum];
	if (ret != -1)
		return ret;
	for (int i = 0; i < N; i++) {
		if (ret == -1) {
			ret = solution(i + 1, sum + v.at(i).second) + v.at(i).first;
		}
		else {
			ret = min(ret, solution(i + 1, sum + v.at(i).second) + v.at(i).first);
		}
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dp, -1, sizeof dp);
	cin >> C >> N;
	for (int i = 0; i < N; i++) {
		int cost, customer;
		cin >> cost >> customer;
		v.push_back(make_pair(cost, customer));
	}
	int ans = solution(0, 0);
	cout << ans << endl;
}