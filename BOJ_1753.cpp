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
vector<ii> v[MAX_V + 1];
int d[MAX_V + 1];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int V, E, st;
	fill(d, d + MAX_V + 1, INF);
	cin >> V >> E >> st;
	while (E--) {
		int start, to, weight;
		cin >> start >> to >> weight;
		v[start].push_back({ weight, to });
	}
	priority_queue < ii, vii, greater<>> pq;
	d[st] = 0;
	pq.push({0, st});
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		int dist = cur.first, idx = cur.second;
		if (d[idx] != dist)
			continue;
		for (auto i : v[idx]) {
			int cost = i.first, nidx = i.second;
			if (d[nidx] > cost + dist) {
				d[nidx] = cost + dist;
				pq.push({ d[nidx], nidx });
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (d[i] == INF)
			cout << "INF" << endl;
		else
			cout << d[i] << endl;
	}
}