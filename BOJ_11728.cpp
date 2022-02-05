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
	vi a, b, ans;
	int n, m;
	cin >> n >> m;
	while (n--) {
		int input;
		cin >> input;
		a.push_back(input);
	}
	while (m--) {
		int input;
		cin >> input;
		b.push_back(input);
	}
	int idxA = 0, idxB = 0;
	while (idxA < a.size() && idxB < b.size()) {
		if (a[idxA] <= b[idxB]) {
			ans.push_back(a[idxA]);
			idxA++;
		}
		else {
			ans.push_back(b[idxB]);
			idxB++;
		}
	}
	if (idxA >= a.size() && idxB < b.size()) {
		for (; idxB < b.size(); idxB++) {
			ans.push_back(b[idxB]);
		}
	}
	else if (idxA < a.size() && idxB >= b.size()) {
		for (; idxA < a.size(); idxA++) {
			ans.push_back(a[idxA]);
		}
	}
	copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
}