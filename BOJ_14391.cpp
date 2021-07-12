#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int paper[4][4];
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &paper[i][j]);
		}
	}
	int ans = 0;
	for (int i = 0; i < (1 << (N * M)); i++) {
		int sum = 0;
		for (int j = 0; j < N; j++) {
			int cur = 0;
			for (int k = 0; k < M; k++) {
				int idx = j * M + k; // 행 우선 방식
				if ((i & (1 << idx)) == 0) {
					cur = cur * 10 + paper[j][k];
				}
				else {
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}
		for (int j = 0; j < M; j++) {
			int cur = 0;
			for (int k = 0; k < N; k++) {
				int idx = k * M + j; // 열 우선 방식
				if ((i & (1 << idx)) != 0) {
					cur = cur * 10 + paper[k][j]; 
				}
				else {
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
}