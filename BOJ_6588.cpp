#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 1000000
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
bool isPrime[MAX_N + 1];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(isPrime, true, sizeof isPrime);
	vi prime;
	for(ll i = 2; i <= MAX_N; i++) {
		if(isPrime[i]) {
			for (ll j = i * i; j <= MAX_N; j += i)
				isPrime[j] = false;
		}
	}
	for(int i = 2; i <= MAX_N; i++) {
		if (isPrime[i])
			prime.push_back(i);
	}
	sort(prime.begin(), prime.end());
	int N;
	while (cin >> N, N) {
		for (int i = 2; i <= N; i++) {
			if (N - i >= 0 && isPrime[i] && isPrime[N - i]) {
				cout << N << " = " << i << " + " << N - i << endl;
				break;
			}
		}
	}
}