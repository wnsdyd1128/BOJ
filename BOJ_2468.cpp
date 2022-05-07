#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 100
#define _CRT_SECURE_NO_DEPRECATE
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int grid[MAX_N + 1][MAX_N + 1];
bool isVisited[MAX_N + 1][MAX_N + 1];
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };
int N;
bool canMove(int y, int x, int h) {
	if (0 <= y && y < N && 0 <= x && x < N && !isVisited[y][x] && grid[y][x] > h)
		return true;
	return false;
}
void dfs(int y, int x, int h) {
	isVisited[y][x] = true;
	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (canMove(ny, nx, h))
			dfs(ny, nx, h);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> grid[i][j];
	}
	int _max = grid[0][0];
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(grid[i][j] > _max)
				_max = grid[i][j];
		}
	}
	int ans = 0;
	for(int h = 0; h <= _max; h++) {
		int cnt = 0;
		memset(isVisited, false, sizeof isVisited);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if(canMove(i, j, h)) {
					cnt++;
					dfs(i, j, h);
				}
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
}