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
	cin.tie(NULL);
	cout.tie(NULL);
	int TC;
	cin >> TC;
	while(TC--) {
		string str;
		cin >> str;
		deque<char> left;
		deque<char> right;
		int cursor = 0;
		bool flag = false;
		for(int i = 0; i < str.length(); i++) {
			if(str[i] == '<') {
				if (!left.empty()) {
					char data = left.back();
					left.pop_back();
					right.push_front(data);
				}
			}
			else if(str[i] == '>') {
				if (!right.empty()) {
					char data = right.front();
					right.pop_front();
					left.push_back(data);
				}
			}
			else if(str[i] == '-') {
				if(!left.empty())
					left.pop_back();
			}
			else
				left.push_back(str[i]);
		}
		while(!left.empty()) {
			cout << left.front();
			left.pop_front();
		}
		while(!right.empty()) {
			cout << right.front();
			right.pop_front();
		}
		cout << endl;
	}
}