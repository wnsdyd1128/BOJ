#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX 1000000
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
bool isPrime[MAX + 1];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(isPrime, true, sizeof isPrime);
	isPrime[0] = isPrime[1] = false;
	int M, N;
	cin >> M >> N;
	for (int i = 2; i <= MAX; i++) {
		if (!isPrime[i])
			continue;
		else {
			for (int j = i * 2; j <= MAX; j += i) {
				isPrime[j] = false;
			}
		}
	}
	for (int i = M; i <= N; i++) {
		if (isPrime[i])
			cout << i << endl;
	}
}