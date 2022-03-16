#include <bits/stdc++.h>
#define endl '\n'
#define MAX_N 10000
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define _CRT_SECURE_NO_DEPRECATE
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int N, L, P;
ii gas[MAX_N + 1];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<int> q;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> gas[i].first >> gas[i].second;
	}
	cin >> L >> P;
	gas[N].first = L;
	gas[N].second = 0;
	N++;
	sort(gas, gas + N);
	int pos = 0, ans = 0;
	for (int i = 0; i < N; i++) {
		int d = gas[i].first - pos;
		while (P < d) {
			if (q.empty()) {
				cout << -1 << endl;
				return 0;
			}
			P += q.top();
			q.pop();
			ans++;
		}
		pos = gas[i].first;
		P -= d;
		q.push(gas[i].second);
	}
	cout << ans << endl;
}