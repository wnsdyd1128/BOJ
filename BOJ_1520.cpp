#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_NM 500
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
int N, M;
int arr[MAX_NM + 1][MAX_NM + 1];
int dp[MAX_NM + 1][MAX_NM + 1];
int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };
bool canMove(int y, int x) {
	if (x <= 0 || x > N || y <= 0 || y > M)
		return false;
	return true;
}
int solution(int y, int x) {
	if (y == M && x == N)
		return 1;
	int& ret = dp[y][x];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (canMove(ny, nx)) {
			if (arr[ny][nx] < arr[y][x]) {
				ret += solution(ny, nx);
			}
		}
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dp, -1, sizeof dp);
	cin >> M >> N;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	cout << solution(1, 1);
}