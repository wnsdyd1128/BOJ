#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 1000
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
ii table[MAX_N + 1];
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	table[1].first = table[1].second = 1;
	for (int i = 2; i <= 1000; i++) {
		table[i].second = table[i - 1].second + i;
		table[i].first = table[i - 1].first + i - 1;
	}
	int pos = 1;
	for (int i = 1; i <= MAX_N; i++) {
		if (table[i].first <= N && N <= table[i].second) {
			pos = i;
			break;
		}
	}
	int diff = N - table[pos].first;
	int a = pos - diff;
	int b = 1 + diff;
	cout << a << ' ' << b << endl;
}