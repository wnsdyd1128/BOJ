#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define _CRT_SECURE_NO_DEPRECATE
#define MAX_R 20
#define MAX_C 20
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };
bool isSelected[26];
char grid[MAX_R + 1][MAX_C + 1];
int dist[MAX_R + 1][MAX_C + 1];
int R, C;
int ans;
bool canMove(int y, int x) {
	if (0 <= y && y < R && 0 <= x && x < C && !isSelected[grid[y][x] - 'A'])
		return true;
	return false;
}
int dfs(int y, int x) {
	int ret = 0;
	isSelected[grid[y][x] - 'A'] = true;
	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(canMove(ny, nx)) {
			ret = max(ret,1 + dfs(ny, nx));
		}
	}
	isSelected[grid[y][x] - 'A'] = false;
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C;
	for(int i = 0; i < R; i++) {
		string str;
		cin >> str;
		for(int j = 0; j < C; j++)
			grid[i][j] = str[j];
	}
	cout << 1 + dfs(0, 0) << endl;
}