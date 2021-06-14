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
	stack<int> s;
	string str;
	int N;
	cin >> N;
	int i = 1;
	bool flag = true;
	while (N--) {
		int num;
		cin >> num;
		while (true) {
			if (s.empty() || s.top() < num) {
				s.push(i);
				str.push_back('+');
				i++;
			}
			else if (s.top() == num) {
				s.pop();
				str.push_back('-');
				break;
			}
			else if (s.top() > num) {
				flag = false;
				break;
			}
		}
	}
	if (flag) {
		for (int i = 0; i < str.length(); i++) {
			cout << str.at(i) << endl;
		}
	}
	else
		cout << "NO" << endl;
}