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
void solution(vi& v, vi& ans, int start) {
	if (ans.size() == 6) {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << ' ';
		}
		cout << endl;
		return;
	}
	for (int i = start; i < v.size(); i++) {
		ans.push_back(v[i]);
		solution(v, ans, i + 1);
		ans.pop_back();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int K;
	while (cin >> K, K) {
		vi v(K);
		vi ans;
		for (int i = 0; i < K; i++) {
			cin >> v[i];
		}
		solution(v, ans, 0);
		cout << endl;
	}
}