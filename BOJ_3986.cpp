#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define _CRT_SECURE_NO_DEPRECATE
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC;
	cin >> TC;
	int ans = 0;
	while (TC--) {
		string str;
		cin >> str;
		stack<char> s;
		for (int i = 0; i < str.length(); i++) {
			if (s.empty()) {
				s.push(str[i]);
			}
			else {
				if (s.top() == str[i])
					s.pop();
				else
					s.push(str[i]);
			}
		}
		if (s.empty())
			ans++;
	}
	cout << ans << endl;
}