#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_H 100
#define MAX_M 100
#define MAX_N 100
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;

int grid[MAX_H + 1][MAX_N + 1][MAX_M + 1];
int H, N, M;
int dz[] = { 0, 0, 0, 0, -1, 1 };
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dx[] = { 1, -1, 0, 0, 0, 0 };
bool canMove(int z, int y, int x) {
	if (0 <= z && z < H && 0 <= y && y < N && 0 <= x && x < M && grid[z][y][x] == 0)
		return true;
	return false;
}
bool isAllRipen() {
	for (int z = 0; z < H; z++) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++)
				if (grid[z][y][x] == 0)
					return false;
		}
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> M >> N >> H;
	for(int i = 0; i < H; i++) {
		for(int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++)
				cin >> grid[i][j][k];
		}
	}
	if (isAllRipen())
		cout << 0 << endl;
	else {
		queue<iii> q;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < M; k++) {
					if (grid[i][j][k] == 1)
						q.push(make_tuple(i, j, k));
				}
			}
		}
		while(!q.empty()) {
			auto [z, y, x] = q.front();
			q.pop();
			for(int i = 0; i < 6; i++) {
				int nz = z + dz[i];
				int ny = y + dy[i];
				int nx = x + dx[i];
				if(canMove(nz, ny, nx)) {
					q.push(make_tuple(nz, ny, nx));
					grid[nz][ny][nx] = grid[z][y][x] + 1;
				}
			}
		}
		int ans = 0;
		bool flag = false;
		for (int i = 0; i < H; i++) {
			if (flag)
				break;
			for (int j = 0; j < N; j++) {
				if (flag)
					break;
				for (int k = 0; k < M; k++) {
					if (grid[i][j][k] == 0) {
						flag = true;
						break;
					}
					ans = max(ans, grid[i][j][k]);
				}
			}
		}
		if (flag)
			cout << -1 << endl;
		else
			cout << ans - 1 << endl;

	}
}