#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_M 10000
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int dp[MAX_M + 1];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC;
	cin >> TC;
	while (TC--) {
		int N, M;
		vi v;
		cin >> N;
		while (N--) {
			int input;
			cin >> input;
			v.push_back(input);
		}
		cin >> M;
		memset(dp, 0, sizeof dp);
		dp[0] = 1;
		for (int i = 0; i < v.size(); i++) {
			for (int j = v.at(i); j <= M; j++) {
				dp[j] += dp[j - v.at(i)];
			}
		}
		cout << dp[M] << endl;
	}
}