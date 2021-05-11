#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#define endl '\n'
#define INF 1000000000
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
	int TC;
	cin >> TC;
	while (TC--) {
		stack<char> stack;
		bool isVPS = true;
		string s;
		cin >> s;
		int length = s.length();
		for (int i = 0; i < length; i++) {
			if (s.at(i) == '(')
				stack.push(s.at(i));
			else {
				if (!stack.empty() && stack.top() == '(') {
					stack.pop();
				}
				else {
					isVPS = false;
					break;
				}
			}
		}
		if (isVPS && stack.empty()) {
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;
	}
}