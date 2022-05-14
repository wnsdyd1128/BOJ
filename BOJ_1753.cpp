#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_V 20000
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
vii v[MAX_V + 1];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int V, E, st;
	cin >> V >> E >> st;
	while(E--) {
		int from, to, weight;
		cin >> from >> to >> weight;
		v[from].push_back(make_pair(weight, to));
	}
	vi dist(MAX_V + 1, INF);
	dist[st] = 0;
	priority_queue<ii, vii, greater<>> q;
	q.push(make_pair(0, st));
	while(!q.empty()) {
		auto [weight, dest] = q.top();
		q.pop();
		if (dist[dest] != weight)
			continue;
		for(auto [w, d] : v[dest]) {
			if(dist[d] > dist[dest] + w) {
				dist[d] = dist[dest] + w;
				q.push(make_pair(dist[d],d));
			}
		}
	}
	for(int i = 1; i <= V; i++) {
		if (dist[i] == INF)
			cout << "INF" << endl;
		else
			cout << dist[i] << endl;
	}
}