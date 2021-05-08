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
int DP[1001][3];
int solution(int idx, int color, vector<pair<int, pair<int, int>>> cost) {
	if (idx == 0) {
		return 0;
	}
	int& ret = DP[idx][color];
	if (ret != 0)
		return ret;
	if (color == 0) {
		// 현재의 원소를 더해주면 DP[idx][color]가 0이 될 수 없다! 
		ret = min(solution(idx - 1, 1, cost), solution(idx - 1, 2, cost)) + cost.at(idx - 1).first;
		return ret;
	}
	else if (color == 1) {
		ret = min(solution(idx - 1, 0, cost), solution(idx - 1, 2, cost)) + cost.at(idx - 1).second.first;
		return ret;
	}
	else {
		ret = min(solution(idx - 1, 0, cost), solution(idx - 1, 1, cost)) + cost.at(idx - 1).second.second;
		return ret;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<pair<int, pair<int, int>>> v; // first : R, second.first : G, second.second : B
	cin >> n;
	for (int i = 0; i < n; i++) {
		int r, g, b;
		cin >> r >> g >> b;
		v.push_back(make_pair(r, make_pair(g, b)));
	}
	DP[1][0] = v.at(0).first;
	DP[1][1] = v.at(0).second.first;
	DP[1][2] = v.at(0).second.second;
	cout << min(solution(n, 0, v), min(solution(n, 1, v), solution(n, 2, v)));

}