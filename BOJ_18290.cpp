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
int n, m;
int grid[11][11];
bool canNotSelect[11][11];
int ans = -10000000;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
void Solution(int cnt, int k, int sum) {
	if (cnt == k) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (canNotSelect[i][j])
				continue;
			bool flag = true;
			for (int iter = 0; iter < 4; iter++) {
				int nx = i + dx[iter];
				int ny = j + dy[iter];
				if (nx > 0 && ny > 0 && nx <= n && ny <= m) {
					if (canNotSelect[nx][ny])
						flag = false;
				}
			}
			if (flag) {
				canNotSelect[i][j] = true;
				Solution(cnt + 1, k, sum + grid[i][j]);
				canNotSelect[i][j] = false;
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int input;
			cin >> input;
			grid[i][j] = input;
		}
	}
	Solution(0, k, 0);
	cout << ans << endl;
}