#include <bits/stdc++.h>
#define endl '\n'
#define MAX_N 1000
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int dp_LIS[MAX_N + 1];
int dp_LDS[MAX_N + 1];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vi v;
	int N;
	cin >> N;
	while (N--) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	for (int i = 0; i < v.size(); i++) {
		dp_LIS[i] = 1;
		for (int j = 0; j < i; j++) {
			if (v.at(j) < v.at(i))
				dp_LIS[i] = max(dp_LIS[i], dp_LIS[j] + 1);
		}
		
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		dp_LDS[i] = 1;
		for (int j = i + 1; j < v.size(); j++) {
			if (v.at(i) > v.at(j))
				dp_LDS[i] = max(dp_LDS[i], dp_LDS[j] + 1);
		}
	}
	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		ans = max(ans, dp_LIS[i] + dp_LDS[i] - 1);
	}
	cout << ans << endl;
}