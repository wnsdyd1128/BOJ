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
int table[26][2];
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC;
	cin >> TC;
	cin.ignore();
	for (int t = 1; t <= TC; t++) {
		memset(table, 0, sizeof table);
		string lhs, rhs;
		getline(cin, lhs);
		getline(cin, rhs);
		for (int i = 0; i < lhs.length(); i++) {
			table[lhs[i] - 'a'][0]++;
		}
		for (int i = 0; i < rhs.length(); i++) {
			table[rhs[i] - 'a'][1]++;
		}
		int cnt = 0;
		for (int i = 0; i < 26; i++) {
			cnt += abs(table[i][0] - table[i][1]);
		}
		cout << "Case #" << t << ": " << cnt << endl;
	}
}