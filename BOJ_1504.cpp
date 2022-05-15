#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000
#define MAX_N 800
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int N;
vii v[MAX_N + 1];
vector<ll> dijkstra(int start) {
	priority_queue<ii, vii, greater<>> q;
	vector<ll> dist(MAX_N + 1, INF);
	dist[start] = 0;
	q.push(make_pair(0, start));
	while(!q.empty()) {
		auto [weight, next] = q.top();
		q.pop();
		if (dist[next] != weight)
			continue;	
		for(auto& [n, w] : v[next]) {
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
	int E;
	cin >> N >> E;
	while(E--) {
		int from, to, weight;
		cin >> from >> to >> weight;
		v[from].push_back(make_pair(to, weight));
		v[to].push_back(make_pair(from, weight));
	}
	int v1, v2;
	cin >> v1 >> v2;
	vector<ll> dist1 = dijkstra(v1);
	vector<ll> dist2 = dijkstra(v2);
	ll ans = dist1[v2] + min(dist2[1] + dist1[N], dist1[1] + dist2[N]);
	cout << (ans >= INF ? -1 : ans) << endl;
}