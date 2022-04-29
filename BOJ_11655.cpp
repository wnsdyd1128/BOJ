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
	cin.tie(nullptr);
	cout.tie(nullptr);
	string str;
	getline(cin, str);
	for(int i = 0; i < str.length(); i++) {
		int ans;
		if (isupper(str[i]))
			ans = ((str[i] - 'A') + 13) % 26 + 'A';
		else if (islower(str[i]))
			ans = ((str[i] - 'a') + 13) % 26 + 'a';
		else
			ans = str[i];
		cout << static_cast<char>(ans);
	}
}