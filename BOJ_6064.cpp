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
	int TC;
	cin >> TC;
	while (TC--) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		x--;
		y--;
		bool flag = false;
		for (int k = x; k < M * N; k += M) { // 배수 관계를 이용해서 접근
			if (k % N == y) {
				cout << k + 1 << endl;
				flag = true;
				break;
			}
		}
		if (!flag)
			cout << -1 << endl;
	}
}