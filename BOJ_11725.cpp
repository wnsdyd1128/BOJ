#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 100000
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int N;
vi v[MAX_N + 1];
int parent[MAX_N + 1];
bool isVisited[MAX_N + 1];
void bfs(int start) {
	queue<int> q;
	q.push(start);
	isVisited[start] = true;
	while(!q.empty()) {
		int next = q.front();
		q.pop();
		for(auto x : v[next]) {
			if(!isVisited[x]) {
				q.push(x);
				isVisited[x] = true;
				parent[x] = next;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;
	for(int i = 0; i < N - 1; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
	bfs(1);
	for (int i = 2; i <= N; i++)
		cout << parent[i] << endl;
}