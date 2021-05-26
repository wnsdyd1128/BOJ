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
ll DP[101][101];
int jump[101][101];
int N;
ll solution(int x, int y) {
	if (x > N || y > N)
		return 0;
	if (x == N && y == N)
		return 1;
	ll& ret = DP[x][y];
	if (ret != -1)
		return ret;
	if (jump[x][y] == 0)
		return ret = 0;
	return ret = solution(x + jump[x][y], y) + solution(x, y + jump[x][y]);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> jump[i][j];
		}
	}
	memset(DP, -1, sizeof DP);
	ll ans = solution(1, 1);
	cout << ans << endl;
}