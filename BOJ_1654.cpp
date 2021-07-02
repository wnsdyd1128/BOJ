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
int K, N;
vi v;
ll check(ll mid) {
	ll sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v.at(i) / mid;
	}
	return sum;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> K >> N;
	while (K--) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	int maxLength = v.at(0);
	for (int i = 1; i < v.size(); i++) {
		max(maxLength, v.at(i));
	}
	ll start = 1;
	ll end = maxLength;
	ll ans = -1;
	ll mid = (start + end) / 2;
	ll res = check(mid);
	while (start + 1 < end) {
		if (res >= N) {
			ans = mid;
			start = mid + 1;
		}
		else
			end = mid - 1;
		mid = (start + end) / 2;
		res = check(mid);
	}
	if (res >= N) {
		ans = mid;
	}
	if (check(end) >= N) {
		ans = end;
	}
	cout << ans << endl;
}