#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
vi list;
ll DP[10000][3];
ll solution(int i, int j) {
	if (i < 0 || j == 3)
		return 0;
	if (i == 0)
		return list.at(i);
	ll& ret = DP[i][j];
	if (ret != -1)
		return ret;
	return ret = max({solution(i - 1, 1), solution(i - 1, j + 1) + list.at(i), solution(i - 2, 1) + list.at(i)});
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(DP, -1, sizeof DP);
	int N;
	cin >> N;
	memset(DP, -1, sizeof DP);
	while (N--) {
		int input;
		cin >> input;
		list.push_back(input);
	}
	int size = list.size();
	cout << solution(size - 1, 1) << endl;
}