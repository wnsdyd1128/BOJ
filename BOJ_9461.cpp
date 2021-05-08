#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#define endl '\n'
using namespace std;

long long int DP[101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int testcase;
	cin >> testcase;
	DP[1] = DP[2] = DP[3] = 1;
	for (int i = 4; i <= 100; i++) {
		DP[i] = DP[i - 2] + DP[i - 3];
	}
	for (int i = 0; i < testcase; i++) {
		int n;
		cin >> n;
		cout << DP[n] << endl;
	}
}