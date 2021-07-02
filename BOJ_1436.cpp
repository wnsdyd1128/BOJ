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
	int cnt = 0;
	int n;
	ll i, ans;
	cin >> n;
	ans = 666;
	for (i = 666; cnt != n; i++) {
		string str = to_string(i);
		int length = str.length();
		for (int j = 0; j + 2 < length; j++) {
			if (str.at(j) == '6' && str.at(j + 1) == '6' && str.at(j + 2) == '6') {
				cnt++;
				break;
			}
		}
		ans = i;
	}
	cout << ans;
}