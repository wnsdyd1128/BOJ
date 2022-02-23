#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
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
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	uint64_t N;
	cin >> N;
	uint64_t start = 0, end = sqrt(INT64_MAX) + 1;
	if (N != 0) {
		while (start <= end) {
			uint64_t mid = (start + end) / 2;
			if (mid * mid < N)
				start = mid + 1;
			else
				end = mid - 1;
		}
	}
	cout << start << endl;
}