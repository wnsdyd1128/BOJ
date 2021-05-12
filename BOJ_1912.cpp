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
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int DP[100000], n;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	vi list;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		list.push_back(input);
	}
	int ans = -INF;
	DP[0] = list.at(0); // DP[i] : 마지막을 i번째 원소로 하는 수열의 합의 max 
	for (int i = 1; i < n; i++) {
		DP[i] = max(0, DP[i - 1]) + list.at(i); // 감소폭이 더 큰 경우 DP[i]를 i번째 원소의 값으로 초기화.
		ans = max(ans, DP[i]);
	}
	cout << ans << endl; // DP[0] ~ DP[n-1] 중 최대값
}