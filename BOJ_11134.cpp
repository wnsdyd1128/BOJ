#include <bits/stdc++.h>
#define endl '\n'
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
	int TC;
	cin >> TC;
	while (TC--) {
		int n, c;
		cin >> n >> c;
		int ans = n / c;
		if (n % c != 0)
			cout << ++ans << endl;
		else
			cout << ans << endl;

	}
}