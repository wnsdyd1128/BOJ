#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 8
#define MAX_M 8
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
bool isVisited[MAX_N + 1][MAX_M + 1];
int ans;
int N, M;
int dy[] = { 0, 0, -1, 1 };
int dx[] = { 1, -1, 0, 0 };
bool canMove(int y, int x, vector<vi>& v) {
	if (0 <= y && y < N && 0 <= x && x < M && !isVisited[y][x] && v[y][x] == 0)
		return true;
	return false;
}
void bfs(int y, int x, vector<vi>& grid) {
	queue<ii> q;
	q.push(make_pair(y, x));
	isVisited[y][x] = true;
	while (!q.empty()) {
		auto [curY, curX] = q.front();
		q.pop();
		for(int i = 0; i < 4; i++) {
			int ny = curY + dy[i];
			int nx = curX + dx[i];
			if(canMove(ny, nx, grid)) {
				q.push(make_pair(ny, nx));
				grid[ny][nx] = 2;
				isVisited[ny][nx] = true;
			}
		}
	}
}
int countSafeArea(const vector<vi>& grid) {
	int ret = 0;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j] == 0)
				ret++;	
		}
	}
	return ret;
}
void solve(const vector<vi>& grid) {
	memset(isVisited, false, sizeof isVisited);
	vector<vi> v(N, vi(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			v[i][j] = grid[i][j];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] == 2) {
				bfs(i, j, v);
			}
		}
	}
	int res = countSafeArea(v);
	ans = max(ans, res);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> M;
	vii space;
	vector<vi> grid(N, vi(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 0)
				space.push_back(make_pair(i, j));
		}
	}
	for (int i = 0; i + 2 < space.size(); i++) {
		for (int j = i + 1; j < space.size(); j++) {
			for (int k = j + 1; k < space.size(); k++) {
				ii f = space[i];
				ii s = space[j];
				ii t = space[k];
				grid[f.first][f.second] = 1;
				grid[s.first][s.second] = 1;
				grid[t.first][t.second] = 1;
				solve(grid);
				grid[f.first][f.second] = 0;
				grid[s.first][s.second] = 0;
				grid[t.first][t.second] = 0;
			}
		}
	}
	cout << ans << endl;
}