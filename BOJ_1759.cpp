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
int L, C;
string input;
bool isVowel(char ch) {
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		return true;
	return false;
}
void solution(int idx, int selected, string str, int countVowels, int countConsonants) {
	if (selected == L) {
		bool isOk = (countVowels >= 1 && countConsonants >= 2);
		if (!isOk)
			return;
		for (int i = 0; i < L; i++) {
			if (str.at(i) == ' ' )
				continue;
			cout << str.at(i);
		}
		cout << endl;
		return;
	}
	if (idx >= input.length())
		return;
	if (!selected || (str.at(selected - 1) != ' ' && str.at(selected - 1) < input.at(idx))) {
		if (isVowel(input.at(idx))) {
			str.at(selected) = input.at(idx);
			solution(idx + 1, selected + 1, str, countVowels + 1, countConsonants);
		}
		else {
			str.at(selected) = input.at(idx);
			solution(idx + 1, selected + 1, str, countVowels, countConsonants + 1);
		}
	}
	str.at(selected) = ' ';
	solution(idx + 1, selected, str, countVowels, countConsonants);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> L >> C;
	string str(L, ' ');
	while (C--) {
		char ch;
		cin >> ch;
		input.push_back(ch);
	}
	sort(input.begin(), input.end());
	solution(0, 0, str, 0, 0);
}