#include <bits/stdc++.h>
#define endl '\n'
#define MAX_V 20000
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int check[MAX_V + 1];
vi v[MAX_V + 1];
bool dfs(int vertex, int distinguisher) {
	check[vertex] = distinguisher;
	for (int i = 0; i < v[vertex].size(); i++) {
		int cur = v[vertex][i];
		if (check[cur] == 0) {
			if (distinguisher == -1) {
				if (!dfs(cur, 1))
					return false;
			}
			else {
				if (!dfs(cur, -1))
					return false;
			}
		}
		else {
			if (check[cur] == check[vertex])
				return false;
		}
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC;
	cin >> TC;
	while (TC--) {
		int n, e;
		cin >> n >> e;
		for (int i = 1; i <= n; i++) {
			v[i].clear();
		}
		memset(check, 0, sizeof check);
		while (e--) {
			int start, to;
			cin >> start >> to;
			v[start].push_back(to);
			v[to].push_back(start);
		}
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			if (check[i] == 0) {
				if (!dfs(i, -1))
					flag = false;
			}
		}
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}