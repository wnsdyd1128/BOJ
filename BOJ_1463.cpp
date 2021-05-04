#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#define endl '\n'
#define INIT 987654321
using namespace std;
int DP[1000000];

int solution(int n) {
	if (n == 1) {
		return 0;
	}
	if (DP[n] != 0) {
		return DP[n];
	}
	int ret1 = INIT, ret2 = INIT;
	if (n % 2 == 0) ret1 = 1 + solution(n / 2);
	if (n % 3 == 0) ret2 = 1 + solution(n / 3);
	DP[n] = min(1 + solution(n - 1), min(ret1, ret2));
	return DP[n];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	cout << solution(n) << endl;
}