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
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int E, S, M;
	cin >> E >> S >> M;
	int i = 1, j = 1, k = 1;
	int ans = 1;
	while (true) {
		if (i == E && j == S && k == M)
			break;
		i = i % 15 + 1; // i++; if (i >= 15) i = 1;
		j = j % 28 + 1; // j++; if (j >= 28) j = 1;
		k = k % 19 + 1; // k++; if (k >= 19) k = 1;
		ans++;
	}
	cout << ans << endl;
}