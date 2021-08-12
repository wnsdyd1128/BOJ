#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 25
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int N;
int matrix[MAX_N + 1][MAX_N + 1];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int cnt;
vi v;
bool canMove(int y, int x) {
	if (x < 0 || y < 0 || x >= N || y >= N)
		return false;
	if (matrix[y][x] == 0)
		return false;
	return true;
}
void dfs(int y, int x) {
	matrix[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (canMove(ny, nx)) {
			cnt++;
			dfs(ny, nx);
		}
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &matrix[i][j]);
		}
	}
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (matrix[j][i] == 1) {
				cnt = 1;
				dfs(j, i);
				v.push_back(cnt);
				res++;
				cnt = 0;
			}
		}
	}
	sort(v.begin(), v.end());
	cout << res << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}