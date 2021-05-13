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
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int DP[101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	DP[1] = 1;
	DP[2] = 0;
	DP[3] = 1;
	for (int i = 4; i <= n; i++) {
		if (DP[i - 1] == 1 || DP[i - 3] == 1) {
			DP[i] = 0;
		}
		else {
			DP[i] = 1;
		}
	}
	if (DP[n] == 1) {
		cout << "SK" << endl;	
	}
	else {
		cout << "CY" << endl;
	}
}