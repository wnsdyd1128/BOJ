#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_M 1000
#define MAX_N 1000
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
int m, n;
int grid[MAX_M + 1][MAX_N + 1];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
bool canMove(int r, int c) {
	if (0 <= r && r < m && 0 <= c && c < n && grid[r][c] == 0)
		return true;
	return false;
}
bool dfs(int r, int c) {
	//isVisited[r][c] = true;
	grid[r][c] = 1;
	if (r == m - 1)
		return true;
	for(int i = 0; i < 4; i++) {
		int y = r + dy[i];
		int x = c + dx[i];
		if(canMove(y, x)) {
			if (dfs(y, x))
				return true;
		}
	}
	return false;
}
int main() {
	cin >> m >> n;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%1d", &grid[i][j]);
		}
	}
	bool flag = false;
	for(int i = 0; i < n; i++) {
		if(!grid[0][i]) {
			if(dfs(0, i)) {
				flag = true;
				break;
			}
		}
	}
	if (flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}