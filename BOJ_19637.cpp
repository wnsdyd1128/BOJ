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
	map<int, string> level;
	vi v;
	int N, M;
	cin >> N >> M;
	while (N--) {
		string str;
		int	power;
		cin >> str >> power;
		if (level.find(power) == level.end())
			level[power] = str;
	}
	for (auto it : level) {
		v.push_back(it.first);
	}
	sort(v.begin(), v.end());
	while (M--) {
		int power;
		cin >> power;
		int ans = *(lower_bound(v.begin(), v.end(), power));
		cout << level[ans] << endl;
	}
}