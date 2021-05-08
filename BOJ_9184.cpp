#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#define endl '\n'
using namespace std;

int DP[51][51][51];
int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (DP[a][b][c] != 0)
		return DP[a][b][c];
	if (a > 20 || b > 20 || c > 20) {
		return w(20, 20, 20);
	}
	if (a < b && b < c) {
		DP[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else {
		DP[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}
	return DP[a][b][c];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, c;
	while (true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
	}
}