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
int n;
int s[20][20];
int solution(int idx, vi first, vi second) {
	if (idx == n) {
		if (!first.size())
			return -1;
		if (!second.size())
			return -1;
		int fs = 0;
		int ss = 0;
		for (int i = 0; i < first.size(); i++) {
			for (int j = 0; j < first.size(); j++) {
				if (i == j)
					continue;
				fs += s[first[i]][first[j]];
			}
		}
		for (int i = 0; i < second.size(); i++) {
			for (int j = 0; j < second.size(); j++) {
				if (i == j)
					continue;
				ss += s[second[i]][second[j]];
			}
		}
		int diff = abs(fs - ss);
		return diff;
	}
	int ans = -1;
	first.push_back(idx);
	int f = solution(idx + 1, first, second);
	if (ans == -1 || (f != -1 && ans > f)) {
		ans = f;
	}
	first.pop_back();
	second.push_back(idx);
	int s = solution(idx + 1, first, second);
	if (ans == -1 || (s != -1 && ans > s))
		ans = s;
	second.pop_back();
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}
	vi first, second;
	cout << solution(0, first, second) << endl;

}