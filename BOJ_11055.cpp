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
int DP[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	vi v;
	cin >> n;
	while (n--) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		DP[i] = v.at(i);
		for (int j = 0; j < i; j++) {
			if (v.at(j) < v.at(i)) {
				DP[i] = max(DP[i], DP[j] + v.at(i));
			}
		}
		ans = max(ans, DP[i]);
	}
	cout << ans << endl;
}