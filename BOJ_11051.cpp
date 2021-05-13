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
long long int DP[1001][1001];
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
long long int solution(int n, int k) {
	if (k == 0 || n == k)
		return 1;
	long long int& ret = DP[n][k];
	if (ret != 0)
		return ret;
	ret = solution(n - 1, k - 1) + solution(n - 1, k);
	ret %= 10007;
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	cout << solution(n, k) << endl;
}