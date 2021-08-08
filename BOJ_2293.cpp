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
int DP[101][10001], n, k;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;

// i번째 이후 j만큼 남은 가치에 대한 DP[i][j]
int solution(int i, int j, int* coin) {
	if (j == 0)
		return 1;
	if (i == n)
		return 0;
	int& ret = DP[i][j];
	if (ret != 0)
		return ret;
	if (j < coin[i]) {
		ret = solution(i + 1, j, coin);
	}
	ret += solution(i + 1, j, coin);
	ret += solution(i + 1, j - coin[i], coin);
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	int* arr = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += solution(i, k, arr);
	}
	cout << ans << endl;
}