#include <bits/stdc++.h>
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

string toBinary(char octal) {
	string str;
	stack<char> s;
	octal -= '0';
	while (octal != 0) {
		if (octal % 2 == 0)
			s.push('0');
		else
			s.push('1');
		octal /= 2;
	}
	if (s.size() != 3) {
		int cnt = 3 - s.size();
		while (cnt--) {
			s.push('0');
		}
	}
	while (!s.empty()) {
		str.push_back(s.top());
		s.pop();
	}
	return str;
}
string solution(string octal) {
	string str;
	for (int i = 0; i < octal.length(); i++) {
		str += toBinary(octal.at(i));
	}
	return str;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string octal;
	cin >> octal;
	string ans = solution(octal);
	while (ans.front() == '0' && ans.length() > 1) {
		ans.erase(0, 1);
	}
	cout << ans << endl;
}