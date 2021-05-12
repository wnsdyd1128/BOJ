#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#define endl '\n'
using namespace std;

int DP[12];
int solution(int n) {
	if (n == 1 || n == 2)
		return n;
	if (n == 3)
		return 4;
	int& ret = DP[n];
	if (ret != 0)
		return ret;
	return ret = solution(n - 1) + solution(n - 2) + solution(n - 3);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC;
	cin >> TC;
	while (TC--) {
		int n;
		cin >> n;
		cout << solution(n) << endl;
	}
}