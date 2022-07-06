#include <bits/stdc++.h>
#define endl '\n'
#define MAX_N 100000
#define MAX_M 300000
#define MAX_W 200000
#define INF MAX_N*MAX_W
#define _CRT_SECURE_NO_DEPRECATE
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> pli;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef tuple<ll, int, int> tp;
typedef vector<tp> vtp;
vii v[MAX_N + 1];
int pathCount[MAX_N + 1];
int N, M;
void dijkstra(int start, int end) {
	// first := total dist, second := count
	vector<pair<ll, int>> dist(MAX_N + 1, { ((ll)INF) + 1, MAX_N + 1 });
	vi cnt(N + 1, 0);
	priority_queue<tp, vtp, greater<>> q;
	dist[start] = { 0, 0 };
	q.push(make_tuple(0, 0, start));
	while (!q.empty()) {
		auto [weight, cnt, next] = q.top();
		q.pop();
		if (dist[next].first != weight)
			continue;
		for (auto [n, w] : v[next]) {
			if (dist[n].first > dist[next].first + w) {
				dist[n].first = dist[next].first + w;
				dist[n].second = dist[next].second + 1;
			}
			else if(dist[n].first == dist[next].first + w)
				pathCount[n] += cnt;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int x, y;
	cin >> N >> M >> x >> y;
	while (M--) {
		int from, to, weight;
		cin >> from >> to >> weight;
		v[from].push_back(make_pair(to, weight));
	}
	dijkstra(x, y);
}