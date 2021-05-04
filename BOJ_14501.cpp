#include <iostream>
#include <cstring>
#define MAX 1500002
#define endl '\n'
using namespace std;

long long int DP[MAX], T[MAX], P[MAX];
int n;
long long int solution(long long int days, int n) {
	if (days == n) {
		return 0;
	}
	if (DP[days] != 0) {
		return DP[days];
	}
	if (days + T[days] <= n) {
		DP[days] += max(solution(days + 1, n), P[days] + solution(days + T[days], n));
	}
	else {
		DP[days] += solution(days + 1, n);
	}
	return DP[days];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> T[i] >> P[i];
	}
	long long int ans = solution(0, n);
	cout << ans << endl;
}