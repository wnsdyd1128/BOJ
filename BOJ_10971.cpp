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
int cost[10][10];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> cost[i][j];
		}
	}
	vi v(N);
	for (int i = 0; i < N; i++) {
		v.at(i) = i;
	}
	int ans = INT32_MAX;
	do {
		int sum = 0;
		bool flag = true;
		for (int i = 0; i < N - 1; i++) {
			if (!cost[v.at(i)][v.at(i + 1)]) {
				flag = false;
				break;
			}
			else {
				sum += cost[v.at(i)][v.at(i + 1)];
			}
		}
		if (flag && cost[v.at(N - 1)][v.at(0)] != 0) {
			sum += cost[v.at(N - 1)][v.at(0)];
			ans = min(ans, sum);
		}

	} while (next_permutation(v.begin(), v.end()));
	cout << ans << endl;
}