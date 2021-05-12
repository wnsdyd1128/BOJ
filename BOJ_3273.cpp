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

//Two Pointer
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, x;
	cin >> n;
	vi v;
	for (int i = 0; i < n; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}
	cin >> x;
	sort(v.begin(), v.end());
	int ans = 0;
	int start = 0, end = n - 1;
	while (start < end) {
		int sum = v.at(start) + v.at(end);
		if (sum == x) {
			start++;
			end--;
			ans++;
		}
		else if (sum > x)
			end--;
		else
			start++;
	}
	cout << ans << endl;
}