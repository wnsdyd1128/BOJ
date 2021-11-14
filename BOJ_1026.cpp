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
	vi va;
	vi vb;
	int N;
	cin >> N;
	int M = N;
	while (N--) {
		int input;
		cin >> input;
		va.push_back(input);
	}
	while (M--) {
		int input;
		cin >> input;
		vb.push_back(input);
	}
	sort(va.begin(), va.end(), greater<>());
	sort(vb.begin(), vb.end());
	int ans = 0;
	for (int i = 0; i < va.size(); i++) {
		ans += va[i] * vb[i];
	}
	cout << ans << endl;
}