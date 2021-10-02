#include <bits/stdc++.h>
#define endl '\n'
#define MAX_N 2000
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int dp[MAX_N + 1][MAX_N + 1];
vi v;
int solution(int i, int j) {
	if (i == j)
		return 1;
	if (i + 1 == j)
		return v[j] == v[i] ? 1 : 0;
	int& ret = dp[i][j];
	if (ret != -1)
		return ret;
	if (v[i] != v[j])
		return ret = 0;
	else
		return ret = solution(i + 1, j - 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n;
	while (n--) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	memset(dp, -1, sizeof dp);
	cin >> m;
	while (m--) {
		int i, j;
		cin >> i >> j;
		i--;
		j--;
		cout << solution(i, j) << endl;
	}
}