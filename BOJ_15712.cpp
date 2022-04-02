#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define _CRT_SECURE_NO_DEPRECATE
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#pragma warning(disable:4996)
using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
// a + ar + ar^2 + ar^3 
// (a + ar)(1 + r^2)

// a + ar + ar^2 + ar^3 + ar^4
// ar^4 + (a + ar)(1 + r^2)
ll a, r, n, MOD;

ll mpow(ll r, ll pow) {
	if (pow == 0)
		return 1;
	if (pow % 2 == 1)
		return (mpow(r, pow - 1) * r) % MOD;
	ll half = mpow(r, pow / 2);
	return (half * half) % MOD;
}
ll solution(ll size) {
	if (size == 1)
		return a % MOD;	
	if (size % 2 == 1)
		return ((a * mpow(r, size - 1)) % MOD + (solution(size / 2) * (1 + mpow(r, size / 2))) % MOD) % MOD;
	return (solution(size / 2) * (1 + mpow(r, size / 2))) % MOD;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> a >> r >> n >> MOD;
	cout << solution(n) << endl;
}