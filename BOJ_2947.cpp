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
vi ans = { 1, 2, 3, 4, 5 };

ostream& operator<<(ostream& os, const vi& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	return os;
}
bool operator==(vi& lhs, vi& rhs) {
	for (int i = 0; i < 5; i++) {
		if (lhs[i] != rhs[i])
			return false;
	}
	return true;
}
void solution(vi& args, int cnt) {
	if (cnt == 4) {
		if (args == ans)
			return;
		else
			solution(args, 0);
	}
	else {
		if (args[cnt] > args[cnt + 1]) {
			swap(args[cnt], args[cnt + 1]);
			cout << args << endl;
			solution(args, cnt + 1);
		}
		else {
			solution(args, cnt + 1);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vi v(5);
	for (int i = 0; i < 5; i++) {
		cin >> v[i];
	}
	solution(v, 0);
}