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
int DP[15][15]; // DP[i][j] : i층 j호

int solution(int i, int j) {
	if (i == 0)
		return j;
	int& ret = DP[i][j];
	if (ret != 0)
		return ret;
	for (int k = 1; k <= j; k++) {
		ret += solution(i - 1, k);
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC;
	cin >> TC;
	while (TC--) {
		int k, n;
		cin >> k >> n;
		cout << solution(k, n) << endl;
	}
}