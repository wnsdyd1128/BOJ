#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 100
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
vi v[MAX_N + 1];
bool isVisited[MAX_N + 1];
queue<int> q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	while (M--) {
		int start, to;
		cin >> start >> to;
		v[start].push_back(to);
		v[to].push_back(start);
	}
	isVisited[1] = true;
	q.push(1);
	int ans = 0;
	while (!q.empty()) {
		int vertex = q.front();
		q.pop();
		for (int i = 0; i < v[vertex].size(); i++) {
			if (!isVisited[v[vertex][i]]) {
				ans++;
				isVisited[v[vertex][i]] = true;
				q.push(v[vertex][i]);
			}
		}
	}
	cout << ans << endl;
}