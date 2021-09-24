#include <bits/stdc++.h>
#define endl '\n'
#define MAX 2000
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
bool matrix[MAX][MAX];
vector<vi> g;
vector<ii> edges;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	g.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		matrix[from][to] = matrix[to][from] = true;
		edges.push_back(make_pair(from, to));
		edges.push_back(make_pair(to, from));
		g[from].push_back(to);
		g[to].push_back(from);
	}
	M *= 2;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			int A = edges[i].first;
			int B = edges[i].second;
			int C = edges[j].first;
			int D = edges[j].second;
			if (A == B || A == C || A == D || B == C || B == D || C == D)
				continue;
			if (!matrix[B][C])
				continue;
			for (int E : g[D]) {
				if (A == E || B == E || C == E || D == E)
					continue;
				cout << 1 << endl;
				return 0;
			}
		}
	}
	cout << 0 << endl;
}