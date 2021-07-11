﻿#include <bits/stdc++.h>
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
	int N, M;
	cin >> N >> M;
	map<string, int> m;
	while (N--) {
		string str;
		cin >> str;
		m[str]++;
	}
	while (M--) {
		string str;
		cin >> str;
		m[str]++;
	}
	int cnt = 0;
	vector<string> v;
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		if ((*iter).second == 2) {
			v.push_back((*iter).first);
			cnt++;
		}
	}
	cout << cnt << endl;
	for (auto i : v) {
		cout << i << endl;
	}
}