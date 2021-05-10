#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#define endl '\n'
using namespace std;

int n;
int DP[101][10];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i < 10; i++) {
		DP[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				DP[i][j] = DP[i - 1][j + 1] % 1000000000;
			}
			else if(1 <= j && j < 9){
				DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % 1000000000;
			}
			else {
				DP[i][j] = DP[i - 1][j - 1] % 1000000000;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += DP[n][i];
	}
	cout << ans % 1000000000;
}