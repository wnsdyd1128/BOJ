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
	int TC;
	cin >> TC;
	vector<ll> v;
	while (TC--) {
		int rope;
		cin >> rope;
		v.push_back(rope);
	}
	sort(v.begin(), v.end(), greater<int>());
	int size = v.size();
	ll ans = -1;
	for (ll i = 0; i < size; i++) {
		ans = max(ans, v.at(i) * (i + 1));
	}
	cout << ans;
}