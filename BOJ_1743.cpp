#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 100
#define MAX_M 100
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
int grid[MAX_N + 1][MAX_M + 1];
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };
int N, M;
bool canMove(int y, int x) {
	if (0 <= y && y < N && 0 <= x && x < M && grid[y][x])
		return true;
	return false;
}
//int dfs(int r, int c) {
//	int ans = 0;
//	grid[r][c] = false;
//	for(int i = 0; i < 4; i++) {
//		int y = r + dy[i];
//		int x = c + dx[i];
//		if (canMove(y, x))
//			ans += 1 + dfs(y, x);
//	}
//	return ans;
//}
int cnt;
void dfs(int r, int c) {
	cnt++;
	grid[r][c] = false;
	for(int i = 0; i < 4; i++) {
		int y = r + dy[i];
		int x = c + dx[i];
		if (canMove(y, x))
			dfs(y, x);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int K;
	cin >> N >> M >> K;
	while(K--) {
		int r, c;
		cin >> r >> c;
		r--;
		c--;
		grid[r][c] = true;
	}
	int ans = 0;
	for(int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (grid[i][j]) {
				dfs(i, j);
				//ans = max(ans, dfs(i, j));
				ans = max(ans, cnt);
				cnt = 0;
			}
		}
	}
	cout << ans << endl;
}