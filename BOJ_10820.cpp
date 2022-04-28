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
	while(true) {
		int lower = 0, upper = 0, number = 0, space = 0;
		string str;
		getline(cin, str);
		for(int i = 0; i < str.length(); i++) {
			if (islower(str[i]))
				lower++;
			else if (isupper(str[i]))
				upper++;
			else if (isdigit(str[i]))
				number++;
			else if (isspace(str[i]))
				space++;
		}
		if (lower + upper + number + space != 0)
			cout << lower << ' ' << upper << ' ' << number << ' ' << space << endl;
		else
			break;
	}
}