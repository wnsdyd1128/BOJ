#include <bits/stdc++.h>
#define endl '\n'
#define INF 20000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 10000
#define MAX_K 20
#define _CRT_SECURE_NO_DEPRECATE
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef tuple<int, int, int> tp;
typedef vector<tp> vtp;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;

vii v[MAX_N + 1];
int N, M, K;
vector<vector<ll>> dijkstra(int start) {
	priority_queue<tp, vtp, greater<>> q;
	// dist 배열의 차원을 늘려 추가 정보를 저장할 수 있다.
	// dist[i][u] := i번만큼 도로를 포장할 수 있을 때, u까지의 최단경로

	vector<vector<ll>> dist(MAX_K + 1, vector<ll>(MAX_N + 1, INF));
	dist[K][start] = 0;
	q.push({ dist[K][start], K, start });
	while(!q.empty()) {
		auto [d, p, cur] = q.top();
		q.pop();
		if (dist[p][cur] < d)
			continue;
		for(auto [nxt, w] : v[cur]) {
			if(dist[p][nxt] > dist[p][cur] + w) {
				dist[p][nxt] = dist[p][cur] + w;
				q.push({ dist[p][nxt], p , nxt });
			}
			if(p > 0 && dist[p - 1][nxt] > dist[p][cur]) {
				dist[p - 1][nxt] = dist[p][cur];
				q.push({ dist[p - 1][nxt], p - 1, nxt });
			}
		}
	}
	return dist;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;
	while(M--) {
		int from, to, weight;
		cin >> from >> to >> weight;
		v[from].push_back(make_pair(to, weight));
		v[to].push_back(make_pair(from, weight));
	}
	vector<vector<ll>> dist = dijkstra(1);
	ll ans = INF;
	for (int i = 0; i <= K; i++)
		ans = min(ans, dist[i][N]);
	cout << ans << endl;
}