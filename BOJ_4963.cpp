#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_W 50
#define MAX_H 50
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
bool grid[MAX_H + 1][MAX_W + 1];
int dy[] = { 0, 0, -1, -1, -1, 1, 1, 1 };
int dx[] = { 1, -1, 0, 1, -1, 0, 1, -1 };
int W, H;
bool canMove(int y, int x) {
	if (0 <= y && y < H && 0 <= x && x < W && grid[y][x])
		return true;
	return false;
}

void dfs(int y, int x) {
	grid[y][x] = false;
	for(int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(canMove(ny, nx)) {
			dfs(ny, nx);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(cin >> W >> H, W + H) {
		for(int i = 0; i < H; i++) {
			for(int j = 0; j < W; j++) {
				int input;
				cin >> input;
				if (input)
					grid[i][j] = true;
				else
					grid[i][j] = false;
			}
		}
		int ans = 0;
		for(int i = 0; i < H; i++) {
			for(int j = 0; j < W; j++) {
				if(canMove(i, j)) {
					dfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
}