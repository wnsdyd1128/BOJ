#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 500
#define MAX_M 500
#define STATE 6
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef tuple<int, int, int, int> tp;
typedef vector<tp> vtp;
char grid[MAX_N + 1][MAX_M + 1];
bool isVisited[MAX_N + 1][MAX_M + 1][STATE + 5];
int N, M;
enum {
	TOP = 0,
	BOTTOM,
	LEFT,
	RIGHT,
	FRONT,
	BACK
};
bool canMove(int y, int x, int s) {
	if (0 <= y && y < N && 0 <= x && x < M && grid[y][x] != '#' && !isVisited[y][x][s])
		return true;
	return false;
}
tp getState(int s) {
	int l, r, u, d;
	switch (s) {
	case TOP:
		l = LEFT;
		r = RIGHT;
		u = BACK;
		d = FRONT;
		break;
	case BOTTOM:
		l = RIGHT;
		r = LEFT;
		u = FRONT;
		d = BACK;
		break;
	case LEFT:
		l = BOTTOM;
		r = TOP;
		u = d = LEFT;
		break;
	case RIGHT:
		l = TOP;
		r = BOTTOM;
		u = d = RIGHT;
		break;
	case FRONT:
		l = r = FRONT;
		u = TOP;
		d = BOTTOM;
		break;
	case BACK:
		l = r = BACK;
		d = TOP;
		u = BOTTOM;
		break;
	default:;
	}
	return make_tuple(l, r, u, d);
}
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			grid[i][j] = str[j];
		}
	}
	int row, col;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (grid[i][j] == 'D') {
				row = i;
				col = j;
				break;
			}
		}
	}
	priority_queue<tp, vtp, greater<>> q;
	q.push(make_tuple(0, BOTTOM, row, col));
	isVisited[row][col][BOTTOM] = true;
	while (!q.empty()) {
		auto [cnt, state, y, x] = q.top();
		q.pop();
		if (grid[y][x] == 'R' && state == BOTTOM) {
			cout << cnt << endl;
			return 0;
		}
		auto [l, r, u, d] = getState(state);
		if (canMove(y, x - 1, l)) {
			if (!(grid[y][x - 1] == 'R' && l != BOTTOM)) {
				isVisited[y][x - 1][l] = true;
				q.push(make_tuple(cnt + 1, l, y, x - 1));
			}
		}
		if (canMove(y, x + 1, r)) {
			if (!(grid[y][x + 1] == 'R' && r != BOTTOM)) {
				isVisited[y][x + 1][r] = true;
				q.push(make_tuple(cnt + 1, r, y, x + 1));
			}
		}
		if (canMove(y - 1, x, u)) {
			if (!(grid[y - 1][x] == 'R' && u != BOTTOM)) {
				isVisited[y - 1][x][u] = true;
				q.push(make_tuple(cnt + 1, u, y - 1, x));
			}
		}
		if (canMove(y + 1, x, d)) {
			if (!(grid[y + 1][x] == 'R' && d != BOTTOM)) {
				isVisited[y + 1][x][d] = true;
				q.push(make_tuple(cnt + 1, d, y + 1, x));
			}
		}
	}
	cout << -1 << endl;
}