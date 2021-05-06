#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#define endl '\n'
using namespace std;

int DP0[41];
int DP1[41];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	DP0[0] = 1;
	DP1[1] = 1;
	int n;
	cin >> n;
	for (int i = 2; i <= 40; i++) {
		DP0[i] = DP0[i - 1] + DP0[i - 2];
		DP1[i] = DP1[i - 1] + DP1[i - 2];
	}
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		cout << DP0[input] << " " << DP1[input] << endl;
	}
}