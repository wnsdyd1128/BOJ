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
vi v;
int n, c;
bool check(int dist) {
	int cnt = 1;
	int start = v[0];
	for (int i = 1; i < v.size(); i++) {
		if (v[i] - start >= dist) {
			cnt++;
			start = v[i];
		}
	}
	return cnt >= c;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> c;
	while (n--) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int start = 1;
	int end = v[v.size() - 1] - v[0];
	int ans = 0;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (check(mid)) {
			ans = max(ans, mid);
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
	cout << ans << endl;
}