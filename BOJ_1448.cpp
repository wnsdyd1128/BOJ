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
	int n;
	vi v;
	cin >> n;
	while (n--) {
		int side;
		cin >> side;
		v.push_back(side);
	}
	sort(v.begin(), v.end());
	int ans = -1;
	for (int i = 2; i < v.size(); i++) {
		if (v[i] < v[i - 1] + v[i - 2])
			ans = max(ans, v[i] + v[i - 1] + v[i - 2]);
	}
	cout << ans << endl;
}