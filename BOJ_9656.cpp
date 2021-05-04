#include <iostream>
#define endl '\n'
#define MAX 1001
using namespace std;

int dp[MAX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 0;
	for (int i = 4; i <= n; i++) {
		if (dp[i - 1] == 0 || dp[i - 3] == 0) {
			dp[i] = 1;
		}
		else {
			dp[i] = 0;
		}
	}
	if (dp[n] == 1) {
		cout << "SK" << endl;
	}
	else {
		cout << "CY" << endl;
	}
}