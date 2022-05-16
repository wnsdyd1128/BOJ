#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 1000
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef tuple<int, int, int> tp;
typedef vector<tp> vtp;
vtp v;
int dp[MAX_N + 1][3];
int N;
int solution(int idx, int color) {
	if (idx < 0)
		return 0;
	int& ret = dp[idx][color];
	if (ret != -1)
		return ret;
	auto [r, g, b] = v[idx];
	if (color == 0)
		ret = min(solution(idx - 1, 1), solution(idx - 1, 2)) + r;
	else if (color == 1)
		ret = min(solution(idx - 1, 0), solution(idx - 1, 2)) + g;
	else
		ret = min(solution(idx - 1, 0), solution(idx - 1, 1)) + b;
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;
	v.resize(N + 1);
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < N; i++) {
		int r, g, b;
		cin >> r >> g >> b;
		v[i] = make_tuple(r, g, b);
	}
	cout << min({ solution(N - 1, 0), solution(N - 1, 1), solution(N - 1, 2) }) << endl;
}