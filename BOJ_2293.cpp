#include <bits/stdc++.h>
#define endl '\n'
#define MAX_V 100000
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;

int dp[MAX_V + 1];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	vi v;
	while (N--) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	dp[0] = 1;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 1; j <= K; j++) {
			if (j - v.at(i) < 0)
				continue;
			dp[j] += dp[j - v.at(i)];
		}
	}
	cout << dp[K] << endl;
}