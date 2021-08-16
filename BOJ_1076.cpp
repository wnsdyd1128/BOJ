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
vector<string> colors = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	map<string, ii> m;
	for (int i = 0, j = 1; i < colors.size(); i++, j *= 10) {
		m[colors.at(i)] = make_pair(i, j);
	}
	string v1, v2, multi;
	cin >> v1 >> v2 >> multi;
	ll sum = m[v1].first * 10 + m[v2].first;
	sum *= m[multi].second;
	cout << sum << endl;
}