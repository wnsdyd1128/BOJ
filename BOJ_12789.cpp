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
	int order = 1;
	int N;
	cin >> N;
	stack<int> s;
	vi v;
	while (N--) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == order)
			order++;
		else {
			if (!s.empty() && s.top() == order) {
				order++;
				s.pop();
				i--;
			}
			else {
				s.push(v[i]);
			}
		}
	}
	while (!s.empty()) {
		if (s.top() == order) {
			order++;
			s.pop();
		}
		else
			break;
	}
	if (s.empty())
		cout << "Nice" << endl;
	else
		cout << "Sad" << endl;

}