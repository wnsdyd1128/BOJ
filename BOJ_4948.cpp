#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#define endl '\n'
#define INF 1000000000
#define _CRT_SECURE_NO_DEPRECATE
#define MAX 270000
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int prime[MAX + 1];
long long int countPrime[MAX + 1];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	prime[0] = prime[1] = 1;
	int n;
	for (int i = 2; i < MAX; i++) {
		if (prime[i] != 0) {
			continue;
		}
		else {
			for (int j = i * 2; j < MAX; j += i) {
				prime[j] = 1;
			}
		}
	}
	for (int i = 2; i < MAX; i++) {
		countPrime[i] = countPrime[i - 1];
		if (prime[i] == 0)
			countPrime[i]++;
	}
	while (cin >> n, n) { // n이 0이면 멈춘다.
		cout << countPrime[2 * n] - countPrime[n + 1] << endl;
	}

}