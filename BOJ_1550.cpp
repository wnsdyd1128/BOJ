#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define _CRT_SECURE_NO_DEPRECATE
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#pragma warning(disable:4996)
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
	string str;
	cin >> str;
	ll ans = 0;
	ll temp = 1;
	for (int i = str.length() - 1; i >= 0; i--) {
		if ('0' <= str[i] && str[i] <= '9')
			ans += (str[i] - '0') * temp;
		else
			ans += (str[i] - 'A' + 10) * temp;
		temp *= 16;
	}
	cout << ans << endl;
}