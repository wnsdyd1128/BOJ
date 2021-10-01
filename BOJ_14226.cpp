#include <bits/stdc++.h>
#define endl '\n'
#define MAX 2000
#define INF 1000000000
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int dist[MAX + 1][MAX + 1];
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int s;
	cin >> s;
	memset(dist, -1, sizeof dist);
	dist[1][0] = 0;
	queue<ii> q;
	q.push({ 1, 0 });
	while (!q.empty()) {
		ii d = q.front();
		q.pop();
		if (d.first + d.second <= MAX && dist[d.first + d.second][d.second] == -1) {
			dist[d.first + d.second][d.second] = dist[d.first][d.second] + 1;
			q.push({ d.first + d.second, d.second });
		}

		if (d.first - 1 >= 0 && dist[d.first - 1][d.second] == -1) {
			dist[d.first - 1][d.second] = dist[d.first][d.second] + 1;
			q.push({ d.first - 1, d.second });
		}

		if (dist[d.first][d.first] == -1) {
			dist[d.first][d.first] = dist[d.first][d.second] + 1;
			q.push({ d.first, d.first });
		}
	}
	int ans = INF;
	for (int i = 0; i <= s; i++) {
		if (dist[s][i] != -1)
			ans = min(ans, dist[s][i]);
	}
	cout << ans << endl;
}