#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 100
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
int dist[MAX_N + 1][MAX_N + 1];
int N, M;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			dist[i][j] = i == j ? 0 : INF;
	}
	for(int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		dist[from - 1][to - 1] = 1;
		dist[to - 1][from - 1] = 1;
	}
	for(int k = 0; k < N; k++) {
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int ans = -1;
	int idx = 0;
	for(int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < N; j++)
			sum += dist[i][j];
		if (ans == -1 || ans > sum) {
			ans = sum;
			idx = i;
		}
	}
	cout << idx + 1 << endl;
}