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

vi merge(vi& lhs, vi& rhs) {
	vi ans;
	int l = 0, r = 0;
	while (l < lhs.size() && r < rhs.size()) {
		if (lhs[l] < rhs[r])
			ans.push_back(lhs[l++]);
		else
			ans.push_back(rhs[r++]);
	}
	for (; l < lhs.size(); l++)
		ans.push_back(lhs[l]);
	for (; r < rhs.size(); r++)
		ans.push_back(rhs[r]);
	return ans;
}

void solution(vi& v) {
	if (v.size() == 1)
		return;
	vi lhs, rhs;
	for (int i = 0; i < v.size() / 2; i++)
		lhs.push_back(v[i]);
	for (int i = v.size() / 2; i < v.size(); i++)
		rhs.push_back(v[i]);
	solution(lhs);
	solution(rhs);
	v = move(merge(lhs, rhs));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vi v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	solution(v);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}