#include <bits/stdc++.h>
#define endl '\n'
#define MAX_LEN 1000
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
pair<char, ii> str[MAX_LEN + 1][MAX_LEN + 1];
int dp[MAX_LEN + 1][MAX_LEN + 1]; // dp[i][j] := 문자열 s(1~i)와 문자열 t(1~j)에 대한 LCS
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s, t;
	cin >> s >> t;
	stack<char> ans;
	for(int i = 0; i < s.length(); i++) {
		for(int j = 0; j < t.length(); j++) {
			if(s[i] == t[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
				str[i + 1][j + 1].second = make_pair(i, j);
			}
			else {
				if(dp[i][j + 1] < dp[i + 1][j]) {
					dp[i + 1][j + 1] = dp[i + 1][j];
					str[i + 1][j + 1].second = { i + 1, j };
				}
				else {
					dp[i + 1][j + 1] = dp[i][j + 1];
					str[i + 1][j + 1].second = { i, j + 1 };
				}
			}
		}
	}
	cout << dp[s.length()][t.length()] << endl;
	int row = s.length();
	int col = t.length();
	while(dp[row][col] != 0) {
		if (s[row - 1] == t[col - 1])
			ans.push(s[row - 1]);
		row = str[row][col].second.first;
		col = str[row][col].second.second;
	}
	while(!ans.empty()) {	
		cout << ans.top();
		ans.pop();
	}
}