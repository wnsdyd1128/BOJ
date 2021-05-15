#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <numeric>
#include <functional>
#include <queue>
#include <vector>
#include <cstring>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int gcd(int x, int y) {
	if (y == 0)
		return x;
	return gcd(y, x % y);
}
int lcm(int x, int y) {
	return (x / gcd(x, y)) * y;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	cout << gcd(n, m) << endl;
	cout << lcm(n, m) << endl;
}