#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX 1000
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int field[MAX + 1][MAX + 1];
bool isVisited[MAX + 1][MAX + 1];
int M, N;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
bool canEverythingRipen() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (field[i][j] == 0)
				return false;
		}
	}
	return true;
}
bool canMove(int y, int x) {
	if (x < 0 || y < 0 || x >= M || y >= N)
		return false;
	if (field[y][x] != 0)
		return false;
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> field[i][j];
		}
	}
	if (canEverythingRipen())
		cout << 0 << endl;
	else {
		queue<ii> q;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (field[i][j] == 1)
					q.push({ i, j });
			}
		}
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (canMove(ny, nx) && field[ny][nx] == 0) {
					field[ny][nx] = field[y][x] + 1;
					q.push({ ny, nx });
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (field[i][j] == 0) {
					cout << -1 << endl;
					return 0;
				}
				ans = max(ans, field[i][j]);
			}
		}
		cout << ans - 1 << endl;
	}
}