#include <bits/stdc++.h>
#define endl '\n'
#define MAX 2000000 // 10^9, Floyd-Warshall에선 20억보다 안전
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
bool canMake[MAX + 1];
vi v;
void solution(int idx, int sum) {
	if (idx == v.size()) {
		canMake[sum] = true;
		return;
	}
	solution(idx + 1, sum + v[idx]);
	solution(idx + 1, sum);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	while (N--) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	solution(0, 0);
	int i = 1;
	for (; canMake[i]; i++) {
	}
	cout << i << endl;
}