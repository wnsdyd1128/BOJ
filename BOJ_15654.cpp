#include <bits/stdc++.h>
#define endl '\n'
#define MAX_N 8
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
vi v;
int N, M;
bool isSelected[MAX_N + 1];
void solution(vi& ans) {
	if (ans.size() == M) {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << ' ';
		}
		cout << endl;
	}
	for (int i = 0; i < v.size(); i++) {
		if (!isSelected[i]) {
			isSelected[i] = true;
			ans.push_back(v[i]);
			solution(ans);
			ans.pop_back();
			isSelected[i] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	while (N--) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());
	vi ans;
	solution(ans);
}