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
	int N;
	cin >> N;
	ll ans = 0;
	for (int start = 1, len = 1; start <= N; start *= 10, len++) { // 자릿수 계산하는 방법
		int end = start * 10 - 1;
		if (end > N) {
			end = N;
		}
		ans += static_cast<ll>(end - start + 1) * len;
	}
	cout << ans << endl;
}