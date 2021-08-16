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
int dp[MAX_LEN + 1][MAX_LEN + 1];
string str[MAX_LEN + 1][MAX_LEN + 1];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str1, str2;
	cin >> str1 >> str2;
	for (int i = 0; i < str1.length(); i++) {
		for (int j = 0; j < str2.length(); j++) {
			if (str1[i] == str2[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
				str[i + 1][j + 1] = str[i][j] + str1.at(i);
			}
			else {
				if (dp[i][j + 1] < dp[i + 1][j]) {
					dp[i + 1][j + 1] = dp[i + 1][j];
					str[i + 1][j + 1] = str[i + 1][j];
				}
				else {
					dp[i + 1][j + 1] = dp[i][j + 1];
					str[i + 1][j + 1] = str[i][j + 1];
				}
			}
		}
	}
	cout << dp[str1.length()][str2.length()] << endl;
	cout << str[str1.length()][str2.length()] << endl;
}