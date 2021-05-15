#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int DP[31][31];
int solution(int n, int k) {
	if (n == k || k == 0)
		return 1;
	int& ret = DP[n][k];
	if (ret != -1)
		return ret;
	return ret = solution(n - 1, k - 1) + solution(n - 1, k);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(DP, -1, sizeof DP);
	int n, k;
	cin >> n >> k;
	cout << solution(n - 1, k - 1) << endl;
}