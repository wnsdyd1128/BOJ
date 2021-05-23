#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
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
ll DP[91][2];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	DP[1][0] = 0;
	DP[1][1] = 1;
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		DP[i][0] = DP[i - 1][0] + DP[i - 1][1];
		DP[i][1] = DP[i - 1][0];
	}
	cout << DP[n][0] + DP[n][1] << endl;
}