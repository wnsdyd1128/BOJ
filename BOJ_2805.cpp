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
int N, M;
vi v;
ll check(ll mid) {
	ll sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v.at(i) >= mid) {
			sum += v.at(i) - mid;
		}
	}
	return sum;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	while (N--) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end(), greater<int>());
	ll maxSize = v.at(0);
	ll start = 0;
	ll end = maxSize;
	ll ans = 0;
	while (start < end) {
		ll mid = (start + end) / 2;
		ll sum = check(mid);
		if (sum >= M) {
			ans = mid;
			start = mid + 1;
		}
		else
			end = mid;
	}
	cout << ans << endl;
}