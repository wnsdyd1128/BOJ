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
deque<int> parse(string str) {
	deque<int> dq;
	int cnt = 0;
	for (int i = 0; i < str.length(); i++) {
		if (isdigit(str.at(i))) {
			cnt = (cnt * 10) + (str.at(i) - '0');
		}
		else {
			if (cnt != 0) {
				dq.push_back(cnt);
				cnt = 0;
			}
		}
	}
	return dq;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC;
	cin >> TC;
	while (TC--) {
		string p;
		bool isReverse = false;
		bool flag = true;
		cin >> p;
		int n;
		cin >> n;
		string str;
		cin >> str;
		deque<int> dq = parse(str);
		for (int i = 0; i < p.length(); i++) {
			if (p.at(i) == 'R') {
				isReverse = !isReverse;
			}
			if (p.at(i) == 'D') {
				if (!dq.empty()) {
					if (isReverse)
						dq.pop_back();
					else
						dq.pop_front();
				}
				else {
					cout << "error" << endl;
					flag = false;
					break;
				}
			}
		}
		if (flag) {
			if (dq.empty())
				cout << "[]" << endl;
			else {
				if (isReverse) {
					cout << "[" << dq.at(dq.size() - 1);
					for (int i = dq.size() - 2; i >= 0; i--) {
						cout << "," << dq.at(i);
					}
					cout << "]" << endl;
				}
				else {
					cout << "[" << dq.at(0);
					for (int i = 1; i < dq.size(); i++) {
						cout << "," << dq.at(i);
					}
					cout << "]" << endl;
				}
			}
		}
	}
}