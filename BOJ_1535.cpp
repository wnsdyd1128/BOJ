#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_H 100
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int dp[MAX_H + 1];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vii v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].first;
	}
	for (int i = 0; i < N; i++) {
		cin >> v[i].second;
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = 100; j > v[i].first; j--) {
			dp[j] = max(dp[j], dp[j - v[i].first] + v[i].second);
		}
	}
	cout << dp[100] << endl;
}