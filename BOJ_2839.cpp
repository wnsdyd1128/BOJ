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
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int DP[5001];
int solution(int weight) {
	if (weight == 0) {
		return 0;
	}
	if (weight < 3)
		return INF;
	int& ret = DP[weight];
	if (ret != -1)
		return ret;
	return ret = min(solution(weight - 3), solution(weight - 5)) + 1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	memset(DP, -1, sizeof DP);
	int ans = solution(n);
	if (ans == INF + 1)
		cout << "-1" << endl;
	else
		cout << ans << endl;
}