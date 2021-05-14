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
long long int DP[81]; // DP[n] : n번째 둘레
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	DP[1] = 1;
	DP[2] = 6;
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		DP[i] = DP[i - 1] + DP[i - 2];
	}
	cout << 2 * (DP[n] + DP[n] + DP[n - 1]) << endl;
}