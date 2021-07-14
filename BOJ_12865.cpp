#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 100
#define MAX_K 100000
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int N, K;
vii v;
int dp[MAX_N + 1][MAX_K + 1];
int solution(int idx, int weight) {
	if (idx == v.size())
		return 0;
	int& ret = dp[idx][weight];
	if (ret != -1)
		return ret;
	if (weight + v.at(idx).first <= K) {
		return ret = max(solution(idx + 1, weight), solution(idx + 1, weight + v.at(idx).first) + v.at(idx).second);
	}
	else
		return ret = solution(idx + 1, weight);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dp, -1, sizeof dp);
	cin >> N >> K;
	while (N--) {
		int weight, value;
		cin >> weight >> value;
		v.push_back(make_pair(weight, value));
	}
	cout << solution(0, 0) << endl;
}