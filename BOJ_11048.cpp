#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int arr[1000][1000];
int DP[1000][1000];
int N, M;
int solution(int x, int y) {
	if (x >= N || y >= M)
		return -INF;
	if (x == (N - 1) && y == (M - 1))
		return arr[x][y];
	int& ret = DP[x][y];
	if (ret != -1)
		return ret;
	return ret = max(solution(x + 1, y), solution(x, y + 1)) + arr[x][y];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	memset(DP, -1, sizeof DP);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	cout << solution(0, 0);
}