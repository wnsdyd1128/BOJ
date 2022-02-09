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
	int N, M;
	cin >> N >> M;
	vi v;
	while (N--) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	int start = 0, end = 0;
	int sum = v[0];
	int ans = 0;
	while (end < v.size()) {
		if (sum == M) {
			sum -= v[start];
			start++;
			end++;
			if (end < v.size()) {
				sum += v[end];
			}
			ans++;
		}
		else if (sum < M) {
			end++;
			if (end < v.size())
				sum += v[end];
		}
		else {
			sum -= v[start];
			start++;
		}
	}
	cout << ans;
}