#include <bits/stdc++.h>
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
int N, ans;
int chess[15]; // chess[i] => i번째 열에 놓인 퀸의 행의 좌표
// 즉, chess[i] = j => i번째 퀸의 좌표가 (j, i)임을 나타냄
int canPlace(int row, int col) {
	for (int i = 0; i < col; i++) {
		if (chess[i] == row || (abs(chess[i] - row) == abs(i - col)))
			return false;
	}
	return true;
}
void solution(int countQueen) {
	if (countQueen == N) {
		ans++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (canPlace(i, countQueen)) { // 하나의 열에 하나의 퀸만 가능하므로 countQueen의 값 자체가 열을 나타내도록 강제
			chess[countQueen] = i;
			solution(countQueen + 1);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	solution(0);
	cout << ans << endl;
}