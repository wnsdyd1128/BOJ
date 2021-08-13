#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_NM 50
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int field[MAX_NM + 1][MAX_NM + 1];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int M, N;
bool canMove(int x, int y) {
	if (x < 0 || y < 0 || x >= M || y >= N)
		return false;
	if (field[x][y] == 0)
		return false;
	return true;
}
void dfs(int x, int y) {
	field[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (canMove(nx, ny)) {
			dfs(nx, ny);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC;
	cin >> TC;
	while (TC--) {
		memset(field, 0, sizeof field);
		int K;
		int ans = 0;
		cin >> M >> N >> K;
		while (K--) {
			int X, Y;
			cin >> X >> Y;
			field[X][Y] = 1;
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (field[i][j] == 1) {
					dfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
}