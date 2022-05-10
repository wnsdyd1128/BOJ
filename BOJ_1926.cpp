#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 500
#define MAX_M 500
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
int ans, cnt;
int N, M;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int grid[MAX_N + 1][MAX_M + 1];
vi v;
bool canMove(int y, int x) {
	if (0 <= y && y < N && 0 <= x && x < M && grid[y][x] != 0)
		return true;
	return false;
}
void dfs(int y, int x) {
	cnt++;
	grid[y][x] = 0;
	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (canMove(ny, nx))
			dfs(ny, nx);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for(int i= 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> grid[i][j];
	}
	v.push_back(0);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(canMove(i, j)) {
				ans++;
				dfs(i, j);
				v.push_back(cnt);
				cnt = 0;
			}
		}
	}
	cout << ans << endl << *max_element(v.begin(), v.end()) << endl;
}