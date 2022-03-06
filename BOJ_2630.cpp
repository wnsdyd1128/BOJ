#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 128
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
int N;
int grid[MAX_N + 1][MAX_N + 1];
int cntBlue, cntWhite;
void solution(int row, int col, int n) {
	for (int i = row; i < row + n; i++) {
		for (int j = col; j < col + n; j++) {
			if (grid[i][j] != grid[row][col]) {
				solution(row, col, n / 2);
				solution(row + n / 2, col, n / 2);
				solution(row, col + n / 2, n / 2);
				solution(row + n / 2, col + n / 2, n / 2);
				return;
			}
		}
	}
	if (grid[row][col])
		cntBlue++;
	else
		cntWhite++;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}
	solution(0, 0, N);
	cout << cntWhite << endl << cntBlue << endl;
}