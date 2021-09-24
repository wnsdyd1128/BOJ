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
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	map<char, char> mbti;
	mbti['E'] = 'I';
	mbti['I'] = 'E';
	mbti['S'] = 'N';
	mbti['N'] = 'S';
	mbti['T'] = 'F';
	mbti['F'] = 'T';
	mbti['J'] = 'P';
	mbti['P'] = 'J';
	string str, ans;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		ans.push_back(mbti[str[i]]);
	}
	cout << ans << endl;
}