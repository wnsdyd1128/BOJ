#include <bits/stdc++.h>
#define endl '\n'
#define MAX 100
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int dist[MAX + 1][MAX + 1];
int maze[MAX + 1][MAX + 1];
int M, N;
bool canMove(int x, int y) {
	if (x <= 0 || y <= 0 || x > N || y > M)
		return false;
	return true;
}
int main() {
	scanf("%d %d", &M, &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}
	memset(dist, -1, sizeof dist);
	dist[1][1] = 0;
	deque<ii> q;
	q.push_back({ 1, 1 });
	while (!q.empty()) {
		ii pos = q.front();
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int nx = pos.first + dx[i];
			int ny = pos.second + dy[i];
			if (canMove(nx, ny) && dist[nx][ny] == -1) {
				if (maze[nx][ny] == 0) {
					dist[nx][ny] = dist[pos.first][pos.second];
					q.push_front({ nx, ny });
				}
				if (maze[nx][ny] == 1) {
					dist[nx][ny] = dist[pos.first][pos.second] + 1;
					q.push_back({ nx, ny });
				}
			}
		}
	}
	cout << dist[N][M] << endl;
}