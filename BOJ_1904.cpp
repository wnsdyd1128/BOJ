﻿#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#define endl '\n'
using namespace std;

int DP[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	DP[1] = 1;
	DP[2] = 2;
	int n;
	cin >> n;
	for (int i = 3; i <= n; i++) {
		DP[i] = DP[i - 1] + DP[i - 2];
		DP[i] %= 15746;
	}
	cout << DP[n];
}