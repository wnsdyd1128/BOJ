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
long long int DP[1001][1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		DP[i][1] = 1;
	}
	for (int i = 1; i <= M; i++) {
		DP[1][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= M; j++) {
			DP[i][j] = (DP[i - 1][j] + DP[i][j - 1] + DP[i - 1][j - 1]) % 1000000007;
		}
	}
	cout << DP[N][M] << endl;
}