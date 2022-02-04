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
	vi v;
	vi ans(2);
	while (N--) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());
	int start = 0;
	int end = v.size() - 1;
	int min = INT32_MAX;
	while (start < end) {
		int sum = v[start] + v[end];
		if (abs(sum) < min) {
			min = abs(sum);
			ans[0] = v[start];
			ans[1] = v[end];
		}

		if (sum > 0) {
			end--;
		}
		else if (sum < 0) {
			start++;
		}
		else {
			ans[0] = v[start];
			ans[1] = v[end];
			break;
		}
	}
	cout << ans[0] << " " << ans[1] << endl;
}