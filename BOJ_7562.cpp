#include <bits/stdc++.h>
#define endl '\n'
#define MAX_I 300
#define INF 1000000000
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int boardSize;
int dist[MAX_I][MAX_I];
int ans = INF;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
bool canMove(int x, int y) {
	if (x < 0 || y < 0 || y >= boardSize || x >= boardSize)
		return false;
	if (dist[x][y] != -1)
		return false;
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC;
	cin >> TC;
	while (TC--) {
		cin >> boardSize;
		queue<ii> q;
		ii start, fin;
		memset(dist, -1, sizeof dist);
		cin >> start.first >> start.second;
		cin >> fin.first >> fin.second;
		dist[start.first][start.second] = 0;
		q.push(start);
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (canMove(nx, ny)) {
					dist[nx][ny] = dist[x][y] + 1;
					q.push({ nx, ny });
				}
			}
		}
		cout << dist[fin.first][fin.second] << endl;
	}
}