#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 20
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef tuple<int, int, int, int, int> tp;
typedef vector<tp> vtp;
int N;
int grid[MAX_N + 1][MAX_N + 1];
bool isVisited[MAX_N + 1][MAX_N + 1];
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };
bool canMoveTo(int y, int x) {
	if (0 <= y && y < N && 0 <= x && x < N && !isVisited[y][x])
		return true;
	return false;
}
void bfs(int sy, int sx) {
	priority_queue<tp, vtp, greater<>> q;
	q.push(make_tuple(0, sy, sx, 2, 0));
	isVisited[sy][sx] = true;
	grid[sy][sx] = 0;
	int ans = 0;
	while (!q.empty()) {
		auto [dist, y, x, weight, growth] = q.top();
		q.pop();
		int feed = grid[y][x];
		if (0 < feed && feed < weight) {
			ans += dist;
			growth++;
			grid[y][x] = 0;
			dist = 0;
			if (weight == growth) {
				weight++;
				growth = 0;
			}
			memset(isVisited, false, sizeof isVisited);
			while (!q.empty())
				q.pop();
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (canMoveTo(ny, nx)) {
				if (0 <= grid[ny][nx] && grid[ny][nx] <= weight) {
					q.push(make_tuple(dist + 1, ny, nx, weight, growth));
					isVisited[ny][nx] = true;
				}
			}
		}
	}
	cout << ans << endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;
	int y = 0, x = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 9) {
				y = i;
				x = j;
			}
		}
	}
	bfs(y, x);
}