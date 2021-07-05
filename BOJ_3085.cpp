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
vector<string> v;
int check(int startRow, int endRow, int startCol, int endCol) {
	int ans = 1;
	for (int i = startRow; i <= endRow; i++) {
		int cnt = 1;
		for (int j = 1; j < v.size(); j++) {
			if (v[i][j] == v[i][j - 1])
				cnt++;
			else
				cnt = 1;
			ans = max(ans, cnt);
		}
	}
	for (int i = startCol; i <= endCol; i++) {
		int cnt = 1;
		for (int j = 1; j < v.size(); j++) {
			if (v[j][i] == v[j - 1][i])
				cnt++;
			else
				cnt = 1;
			ans = max(ans, cnt);
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	while (N--) {
		string str;
		cin >> str;
		v.push_back(str);
	}
	N = v.size();
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j + 1 < N) {
				swap(v[i][j], v[i][j + 1]);
				ans = max(ans, check(i, i, j, j + 1));
				swap(v[i][j], v[i][j + 1]);
			}
			if (i + 1 < N) {
				swap(v[i][j], v[i + 1][j]);
				ans = max(ans, check(i, i + 1, j, j));
				swap(v[i][j], v[i + 1][j]);
			}
		}
	}
	cout << ans << endl;
}