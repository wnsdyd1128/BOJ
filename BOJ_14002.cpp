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
int pos[MAX_N + 1]; // index[i] : dp[i]에서 i - 1 번째 항의 위치
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vi v(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> v.at(i);
	}
	int ans = 0;
	int idx = 0;
	stack<int> s;
	for (int i = 1; i <= v.size() - 1; i++) {
		dp[i] = 1;
		pos[i] = 0;
		for (int j = 1; j < i; j++) {
			if (v.at(j) < v.at(i) && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				pos[i] = j;
			}
		}
		if (ans < dp[i]) {
			ans = dp[i];
			idx = i;
		}
	}
	cout << ans << endl;
	while (idx != 0) {
		s.push(v.at(idx));
		idx = pos[idx];
	}
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
}