#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 10000
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int N;
int maxVertex;
int maxWeight;
vii v[MAX_N + 1];
bool isVisited[MAX_N + 1];
void dfs(int vertex, int weight) {
	if(weight > maxWeight) {
		maxWeight = weight;
		maxVertex = vertex;
	}
	isVisited[vertex] = true;
	for(auto& i : v[vertex]) {
		auto& [next, w] = i;
		if (!isVisited[next])
			dfs(next, weight + w);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;
	int M = N - 1;
	while(M--) {
		int from, to, weight;
		cin >> from >> to >> weight;
		v[from].push_back(make_pair(to, weight));
		v[to].push_back(make_pair(from, weight));
	}
	dfs(1, 0);
	memset(isVisited, false, sizeof isVisited);
	maxWeight = 0;
	dfs(maxVertex, 0);
	cout << maxWeight << endl;
}