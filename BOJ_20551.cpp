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
	int N, M;
	cin >> N >> M;
	vi v;
	while (N--) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());
	while (M--) {
		int d;
		cin >> d;
		if (binary_search(v.begin(), v.end(), d)) {
			cout << lower_bound(v.begin(), v.end(), d) - v.begin() << endl;
		}
		else
			cout << -1 << endl;
	}
}