#include <bits/stdc++.h>
#define endl '\n'
#define MAX_N 100000
#define MAX_G 5
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int dp[MAX_N + 1][MAX_G + 1];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vii v;

	while (N--) {
		int A, B;
		cin >> A >> B;
		v.push_back(make_pair(A, B));
	}
	int maxStudent = 1;
	int minGrade = min(v[0].first, v[0].second);

	dp[0][v[0].first] = 1;
	dp[0][v[0].second] = 1;
	for (int i = 1; i < v.size(); i++) {
		dp[i][v[i].first] = dp[i - 1][v[i].first] + 1;
		if (dp[i][v[i].first] > maxStudent) {
			maxStudent = dp[i][v[i].first];
			minGrade = v[i].first;
		}
		if (v[i].first == v[i].second)
			continue;
		dp[i][v[i].second] = dp[i - 1][v[i].second] + 1;
		if (dp[i][v[i].second] > maxStudent) {
			maxStudent = dp[i][v[i].second];
			minGrade = v[i].second;
		}
	}
	cout << maxStudent << ' ' << minGrade << endl;
}