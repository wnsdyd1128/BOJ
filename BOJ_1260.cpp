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
bool isVisited[MAX_N + 1];
vi v[MAX_N + 1];
queue<int> q;
void dfs(int depth) {
	isVisited[depth] = true;
	cout << depth << ' ';
	for(auto i : v[depth]) {
		if (!isVisited[i])
			dfs(i);
	}
}

void bfs() {
	while(!q.empty()) {
		int vertex = q.front();
		cout << vertex << ' ';
		q.pop();
		for(auto i : v[vertex]) {
			if(!isVisited[i]) {
				q.push(i);
				isVisited[i] = true;
			}
		}
	}
}
int main() {
	int N, M;
	int start;
	cin >> N >> M >> start;
	while(M--) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
	for(int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end());
	}
	dfs(start);
	cout << endl;
	q.push(start);
	memset(isVisited, false, sizeof isVisited);
	isVisited[start] = true;
	bfs();
}