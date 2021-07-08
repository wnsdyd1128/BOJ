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

//bool check(string& str) {
//	int ja = 0;
//	int mo = 0;
//	for (char x : str) {
//		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
//			mo++;
//		}
//		else
//			ja++;
//	}
//	return ja >= 2 && mo >= 1;
//}
//void solution(int n, vector<char>& alpha, string password, int i) {
//	if (password.length() == n) {
//		if (check(password)) {
//			cout << password << endl;
//		}
//		return;
//	}
//	if (i >= alpha.size()) {
//		return;
//	}
//	solution(n, alpha, password + alpha[i], i + 1);
//	solution(n, alpha, password, i + 1);
//}
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