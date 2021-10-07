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
	int N, M;
	cin >> N;
	while (N--) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());
	cin >> M;
	vi ans;
	while (M--) {
		int i;
		cin >> i;
		if (binary_search(v.begin(), v.end(), i))
			ans.push_back(1);
		else
			ans.push_back(0);
	}
	for (auto i : ans) {
		cout << i << ' ';
	}
}