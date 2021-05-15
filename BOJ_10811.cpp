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
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vi arr;
	for (int i = 1; i <= n; i++) {
		arr.push_back(i);
	}
	while (m--) {
		int i, j;
		cin >> i >> j;
		i--;
		reverse(arr.begin() + i, arr.begin() + j);
	}
	copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
	/*for (int i = 0; i < n - 1; i++) {
		cout << arr.at(i) << " ";
	}
	cout << arr.at(n - 1);*/
}