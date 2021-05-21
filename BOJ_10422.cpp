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
#define MOD 1000000007
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;

//Catalan Number
//DP[n] = 괄호 n쌍을 사용했을 때의 VPS 개수 
ll DP[5001];


// solution(n) : 괄호 n쌍을 이용한 모든 VPS의 개수 
// Top-Down
ll solution(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	ll& ret = DP[n];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i < n; i++) {
		ret += ((solution(i) % MOD) * (solution(n - i - 1) % MOD)) % MOD;
	}
	return ret %= MOD;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(DP, -1, sizeof DP);
	DP[0] = DP[1] = 1;
	int TC;
	cin >> TC;
	while (TC--) {
		int n;
		cin >> n;
		if (n % 2 == 1)
			cout << "0" << endl;
		else {
			n /= 2;

			// Bottom-Up
			// 
			//for (int i = 2; i <= n; i++) {
			//	DP[i] = 0;
			//	for (int j = 0; j < i; j++) {
			//		// BOJ_10430 참고
			//		DP[i] += (((DP[j] % MOD) * (DP[i - j - 1] % MOD)) % MOD);
			//	}
			//}
			//cout << DP[n] % MOD << endl;

			cout << solution(n)<< endl;
		}
	}
}