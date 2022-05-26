#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 100
#define MAX_M 100
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef tuple<int, int, int> tp;
typedef vector<tp> vtp;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int grid[MAX_N + 1][MAX_M + 1];
bool isVisited[MAX_N + 1][MAX_M + 1];
int N, M;
bool canMove(int y, int x) {
	if (0 <= y && y < N && 0 <= x && x < M && !isVisited[y][x])
		return true;
	return false;
}

void bfs(int y, int x) {
	priority_queue<tp, vtp, greater<>> q;
	q.push(make_tuple(0, y, x));
	isVisited[y][x] = true;
	while (!q.empty()) {
		auto [cnt, curY, curX] = q.top();
		q.pop();
		if (curY == N - 1 && curX == M - 1) {
			cout << cnt << endl;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int ny = curY + dy[i];
			int nx = curX + dx[i];
			if (canMove(ny, nx)) {
				if (grid[ny][nx] == 1) {
					q.push(make_tuple(cnt + 1, ny, nx));
					isVisited[ny][nx] = true;
				}
				else {
					q.push(make_tuple(cnt, ny, nx));
					isVisited[ny][nx] = true;
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			int state = str[j] - '0';
			grid[i][j] = state;
		}
	}
	bfs(0, 0);
}