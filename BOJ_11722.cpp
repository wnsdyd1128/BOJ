#include <bits/stdc++.h>
#define endl '\n'
#define MAX_N 1000
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int dp[MAX_N + 1];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vi v;
	int N;
	cin >> N;
	while (N--) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	/*reverse(v.begin(), v.end());
	int ans = 0; 
	for (int i = 0; i < v.size(); i++) { // i번째에서 끝나는 LDS
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (v.at(j) < v.at(i))
				dp[i] = max(dp[j] + 1, dp[i]);
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;*/
	int ans = 0;
	for (int i = v.size() - 1; i >= 0; i--) { // i번째에서 시작하는 LDS
		dp[i] = 1;
		for (int j = i + 1; j < v.size(); j++) {
			if (v.at(i) > v.at(j))
				dp[i] = max(dp[j] + 1, dp[i]);
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}