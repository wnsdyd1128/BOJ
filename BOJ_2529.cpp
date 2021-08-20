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
string signs;
vector<string> ans;
bool isSelected[10];
bool isMeet(char x, char y, char op) {
	if (op == '<')
		return x > y ? false : true;
	else
		return x < y ? false : true;
}
void solution(int idx, string num) {
	if (idx == signs.size() + 1) {
		ans.push_back(num);	
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (isSelected[i])
			continue;
		if (idx == 0 || isMeet(num[idx - 1], i + '0', signs[idx - 1])) {
			isSelected[i] = true;
			solution(idx + 1, num + to_string(i));
			isSelected[i] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int K;
	memset(isSelected, false, sizeof isSelected);
	cin >> K;
	while (K--) {
		char sign;
		cin >> sign;
		signs.push_back(sign);
	}
	solution(0, "");
	auto p = minmax_element(ans.begin(), ans.end());
	cout << *p.second << endl;
	cout << *p.first << endl;
}