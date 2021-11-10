#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define _CRT_SECURE_NO_DEPRECATE
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
	map<string, int> m;
	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		m[str]++;
	}
	map<string, int>::iterator it = m.begin();
	int max = -1;
	string ans;
	for (; it != m.end(); it++) {
		if (max < it->second) {
			max = it->second;
			ans = it->first;
		}
		else if (max == it->second) {
			ans = min(ans, it->first);
		}
	}
	cout << ans << endl;
}