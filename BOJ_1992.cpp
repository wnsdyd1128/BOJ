#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 64
#define _CRT_SECURE_NO_DEPRECATE
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef tuple<int, int, int> tp;
typedef vector<tp> vtp;
int grid[MAX_N + 1][MAX_N + 1];
int N;
void solution(int row, int col, int scale, bool flag) {
	for (int i = row; i < row + scale; i++) {
		for (int j = col; j < col + scale; j++) {
			if (grid[row][col] != grid[i][j]) {
				flag = false;
				cout << "(";
				int half = scale / 2;
				solution(row, col, half, true);
				solution(row, col + half, half, true);
				solution(row + half, col, half, true);
				solution(row + half, col + half, half, true);
				cout << ")";
				return;
			}
		}
	}
	if (flag) {
		cout << grid[row][col];
		return;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++)
			grid[i][j] = str[j] - '0';
	}
	solution(0, 0, N, true);
}