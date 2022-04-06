#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 1000
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
int table[MAX_N + 1][MAX_N + 1];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, col, row;
	cin >> n >> col >> row;
	col--; row--;
	for(int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> table[i][j];
	}
	bool flag = true;
	for(int i = 0; i < n; i++) {
		if (table[col][row] < table[i][row])
			flag = false;
		if (table[col][row] < table[col][i])
			flag = false;
	}
	if (flag)
		cout << "HAPPY" << endl;
	else
		cout << "ANGRY" << endl;
}