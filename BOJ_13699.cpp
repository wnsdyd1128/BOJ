#include <iostream>
using namespace std;

unsigned long long int DP[36];
unsigned long long int solution(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	if (DP[n] != 0) {
		return DP[n];
	}
	for (int i = 0; i < n; i++) {
		DP[n] += solution(i) * solution(n - 1 - i);
	}
	return DP[n];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	unsigned long long int answer;
	answer = solution(n);
	cout << answer;
}