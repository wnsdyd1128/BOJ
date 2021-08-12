#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_NM 100
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int grid[MAX_NM + 1][MAX_NM + 1];
bool isVisited[MAX_NM + 1][MAX_NM + 1];
int countPath[MAX_NM + 1][MAX_NM + 1];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int N, M;
bool canMove(int y, int x) {
	if (x < 0 || y < 0 || x >= M || y >= N)
		return false;
	if (grid[y][x] == 0)
		return false;
	return true;
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &grid[i][j]);
		}
	}
	int ans = 0;
	queue<ii> q;
	q.push({ 0, 0 });
	isVisited[0][0] = true;
	countPath[0][0] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (canMove(y + dy[i], x + dx[i]) && !isVisited[y + dy[i]][x + dx[i]]) {
				q.push({ y + dy[i], x + dx[i] });
				isVisited[y + dy[i]][x + dx[i]] = true;
				countPath[y + dy[i]][x + dx[i]] = countPath[y][x] + 1;
			}
		}
	}
	cout << countPath[N - 1][M - 1] << endl;
}