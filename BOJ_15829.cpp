#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MOD 1234567891
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
	int L;
	cin >> L;
	string str;
	cin >> str;
	ll r = 1;
	ll res = 0;

	for (int i = 0; i < L; i++) {
		res += ((str.at(i) - 'a' + 1) * r ) % MOD;
		r *= 31;
		r %= MOD;
	}
	cout << res % MOD;
}