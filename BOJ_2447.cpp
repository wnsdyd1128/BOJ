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
void solution(int row, int scale) {
	if (scale == 1) {
		cout << '*';
		return;
	}	
	if (row < scale / 3 * 2 && row >= scale / 3) {
		solution(row % (scale / 3), scale / 3);
		for (int i = 0; i < scale / 3; i++)
			cout << ' ';
		solution(row % (scale / 3), scale / 3);
	}
	else {
		for (int i = 0; i < 3; i++) {
			solution(row % (scale / 3), scale / 3);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		solution(i, n);
		cout << endl;
	}
}