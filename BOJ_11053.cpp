#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#define endl '\n'
#define INF 1000000000
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int DP[1001];
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// DP[i] : 마지막 인덱스가 i인 LIS의 길이
	int n;
	cin >> n;
	vi list;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		list.push_back(input);
	}
	for (int i = 0; i < n; i++) {
		DP[i] = 1;
		for (int j = 0; j < i; j++) {
			if (list.at(j) < list.at(i)) {
				DP[i] = max(DP[i], DP[j] + 1);
			}
		}
		ans = max(ans, DP[i]);
	}
	cout << ans << endl;
}