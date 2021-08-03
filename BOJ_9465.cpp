#include <bits/stdc++.h>
#define endl '\n'
#define MAX_N 100000
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int dp[MAX_N + 1][3]; // dp[i][0] : i번째 행 아무 것도 선택 X, dp[i][1] : 위 선택, dp[i][2] : 아래 선택
int arr[2][MAX_N + 1];
enum {
	NONE,
	UP,
	DOWN
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC;
	cin >> TC;
	while (TC--) {
		int n;
		cin >> n;
		memset(dp, -1, sizeof dp);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		dp[0][NONE] = 0;
		dp[0][UP] = arr[0][0];
		dp[0][DOWN] = arr[1][0];
		for (int i = 1; i < n; i++) {
			dp[i][NONE] = max({ dp[i - 1][NONE], dp[i - 1][UP], dp[i - 1][DOWN] });
			dp[i][UP] = max(dp[i - 1][NONE] + arr[0][i], dp[i - 1][DOWN] + arr[0][i]);
			dp[i][DOWN] = max(dp[i - 1][NONE] + arr[1][i], dp[i - 1][UP] + arr[1][i]);
		}
		cout << max({ dp[n - 1][NONE], dp[n - 1][UP], dp[n - 1][DOWN] }) << endl;
	}
}