#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
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
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vi p;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		p.push_back(input);
	}
	sort(p.begin(), p.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (n - i) * p.at(i);
	}
	cout << ans << endl;
}