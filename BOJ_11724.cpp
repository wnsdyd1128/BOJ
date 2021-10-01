#include <bits/stdc++.h>
#define endl '\n'
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
int ans;
bool isVisited[MAX_N + 1];
void dfs(int vertex) {
	isVisited[vertex] = true;
	for (int i = 0; i < v[vertex].size(); i++) {
		if (!isVisited[v[vertex][i]]) {
			dfs(v[vertex][i]);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	v.resize(n + 1);
	while (m--) {
		int start, to;
		cin >> start >> to;
		v[start].push_back(to);
		v[to].push_back(start);
	}
	for (int u = 1; u <= n; u++) {
		if (!isVisited[u]) {
			dfs(u);
			ans++;
		}
	}
	cout << ans << endl;
}