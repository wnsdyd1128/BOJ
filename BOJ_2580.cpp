#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
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
int board[9][9];

bool canPlace(int y, int x, int k) {
	for (int i = 0; i < 9; i++) {
		if (board[i][x] == k)
			return false;
		if (board[y][i] == k)
			return false;
	}
	for (int i = y / 3 * 3; i < y / 3 * 3 + 3; i++) {
		for (int j = x / 3 * 3; j < x / 3 * 3 + 3; j++) {
			if (board[i][j] == k)
				return false;
		}
	}
	return true;
}
void solution(int y, int x) {
	if (y == 9) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << endl;
			}
			cout << endl;
		}
		exit(0);
	}
	if (board[y][x] != 0) {
		if (x == 8)
			solution(y + 1, 0);
		else
			solution(y, x + 1);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (canPlace(y, x, i)) {
				board[y][x] = i;
				if (x == 8)
					solution(y + 1, 0);
				else
					solution(y, x + 1);
				board[y][x] = 0;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
		}
	}
	solution(0, 0);
}