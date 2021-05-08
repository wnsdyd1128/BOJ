#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#define endl '\n'
using namespace std;

// 정수 삼각형
int n;
int DP[501][501];
int solution(int i, int j, int** arr) {
	if (i == n) {
		return 0;
	}
	int& ret = DP[i][j];
	if (ret != 0) {
		return ret;
	}
	return ret = max(solution(i + 1, j, arr), solution(i + 1, j + 1, arr)) + arr[i][j];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> arr[i][j];
		}
	}
	cout << solution(0, 0, arr);
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;

}