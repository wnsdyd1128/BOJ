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
bool compare(int i, int j) {
	int a = i % 2;
	int b = j % 2;
	if (a < b)
		return false;
	if (a > b)
		return true;
	return i > j;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vi v;
	int A, B, C;
	cin >> A >> B >> C;
	v.push_back(A);
	v.push_back(B);
	v.push_back(C);
	v.push_back(A * B);
	v.push_back(B * C);
	v.push_back(A * C);
	v.push_back(A * B * C);
	sort(v.begin(), v.end(), compare);
	cout << v[0] << endl;
}