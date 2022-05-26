#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 1000
#define MAX_M 1000
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef tuple<int, int, int, bool> tp;
typedef vector<tp> vtp;
int N, M;
int grid[MAX_N + 1][MAX_M + 1];
bool isVisited[MAX_N + 1][MAX_M + 1][2]; // 1 := 이전에 벽을 부수고 왔음, 0 := 아직 부순 적 없이 옴.
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };
bool canMove(int y, int x, int flag) {
	if (0 <= y && y < N && 0 <= x && x < M && !isVisited[y][x][flag])
		return true;
	return false;
}
void bfs(int y, int x) {
	queue<tp> q;
	q.push(make_tuple(1, y, x, false)); // true := 이전에 벽을 부숨, false := 아직 부수지 않음
	isVisited[y][x][0] = true;
	while (!q.empty()) {
		auto [cnt, curY, curX, flag] = q.front();
		q.pop();
		if (curY == N - 1 && curX == M - 1) {
			cout << cnt << endl;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int ny = curY + dy[i];
			int nx = curX + dx[i];
			if (canMove(ny, nx, flag)) {
				if (grid[ny][nx] == 1) {
					if (!flag) {
						q.push(make_tuple(cnt + 1, ny, nx, !flag));
						isVisited[ny][nx][1] = true;
					}
				}
				else {
					q.push(make_tuple(cnt + 1, ny, nx, flag));
					isVisited[ny][nx][flag] = true;
				}
			}
		}
	}
	cout << -1 << endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
			grid[i][j] = str[j] - '0';
	}
	bfs(0, 0);
}