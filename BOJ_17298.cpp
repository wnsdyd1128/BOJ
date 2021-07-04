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
	vi v;
	stack<int> s;
	int N;
	cin >> N;
	vi ans(N);
	while (N--) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		while (true) {
			if (s.empty() || s.top() > v.at(i))
				break;
			s.pop();
		}
		if (s.empty())
			ans.at(i) = -1;
		else
			ans.at(i) = s.top();
		s.push(v.at(i));
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans.at(i) << ' ';
	}
}