#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 1000
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
vector<vi> v;
bool isVisited[MAX_N + 1];
queue<int> q;
void dfs(int vertex) {
	cout << vertex << ' ';
	isVisited[vertex] = true;
	for (int i = 0; i < v[vertex].size(); i++) {
		if (!isVisited[v[vertex][i]]) {
			dfs(v[vertex][i]);
		}
	}
}
void bfs(int vertex) {
	while (!q.empty()) {
		vertex = q.front();
		cout << vertex << ' ';
		q.pop();
		for (auto i : v[vertex]) {
			if (!isVisited[i]) {
				isVisited[i] = true;
				q.push(i);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, V;
	cin >> N >> M >> V;
	v.resize(N + 1);
	while (M--) {
		int start, to;
		cin >> start >> to;
		v[start].push_back(to);
		v[to].push_back(start);
	}
	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end());
	}
	dfs(V);
	cout << endl;
	memset(isVisited, false, sizeof isVisited);
	q.push(V);
	isVisited[V] = true;
	bfs(V);
}