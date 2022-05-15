#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 10000
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vii v[MAX_N + 1];

vi dijkstra(int start) {
	priority_queue<ii, vii, greater<>> q;
	vi dist(MAX_N + 1, INF);
	q.push(make_pair(0, start));
	dist[start] = 0;
	while(!q.empty()) {
		auto [weight, next] = q.top();
		q.pop();
		if (dist[next] != weight)
			continue;
		for(auto [n, w] : v[next]) {
			if(dist[n] > dist[next] + w) {
				dist[n] = dist[next] + w;
				q.push(make_pair(dist[n], n));
			}
		}
	}
	return dist;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int TC;
	cin >> TC;
	while(TC--) {
		int N, D, start;
		cin >> N >> D >> start;
		while(D--) {
			int from, to, weight;
			cin >> to >> from >> weight;
			v[from].push_back(make_pair(to, weight));
		}
		vi dist = dijkstra(start);
		int cnt = 0;
		int ans = 0;
		for(int i = 1; i <= N; i++) {
			if (dist[i] != INF) {
				cnt++;
				ans = max(ans, dist[i]);
			}
		}
		cout << cnt << ' ' << ans << endl;
		for (int i = 0; i < MAX_N + 1; i++)
			v[i].clear();
	}

}