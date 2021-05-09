#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#define endl '\n'
using namespace std;

int n;
int DP[301];
int dp[301][2];
int solution(int cur, int* score) {
	if (cur < 0)
		return 0;
	int& ret = DP[cur];
	if (ret != 0)
		return ret;
	ret = score[cur];
	ret += max(solution(cur - 3, score) + score[cur - 1], solution(cur - 2, score));
	return ret;
}
int solution2(int cur, int cnt, int* score) {
	if (cur < 0)
		return 0;
	int& ret = dp[cur][cnt];
	if (ret != 0)
		return ret;
	if (cnt == 0) {
		return ret = max(solution2(cur - 1, 1, score), solution2(cur - 2, 0, score)) + score[cur];
	}
	else {
		return ret = solution2(cur - 2, 0, score) + score[cur];
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int* score = new int[n + 1];
	score[0] = 0; // 시작
	for (int i = 1; i <= n; i++) {
		cin >> score[i];
	}
	cout << solution2(n, 0, score);
}