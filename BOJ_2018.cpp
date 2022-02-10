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
	int N;
	cin >> N;
	int start = 1, end = 1;
	int ans = 0;
	int sum = 1;
	while (end <= N) {
		if (sum == N) {
			ans++;
			sum -= start;
			start++;
			end++;
			if (end <= N) {
				sum += end;
			}
		}
		else if (sum < N) {
			end++;
			if (end <= N) {
				sum += end;
			}
		}
		else {
			sum -= start;
			start++;
		}
	}
	cout << ans << endl;
}