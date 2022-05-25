#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 200000
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
bool isVisited[MAX_N + 1];
bool canMove(int pos) {
	if (0 <= pos && pos <= 200000 && !isVisited[pos])
		return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N, K;
	cin >> N >> K;
	priority_queue<ii, vii, greater<>> q;
	q.push(make_pair(0, N));
	isVisited[N] = true;
	while (!q.empty()) {
		auto [cnt, pos] = q.top();
		q.pop();
		if (pos == K) {
			cout << cnt << endl;
			return 0;
		}
		if (canMove(pos - 1)) {
			q.push(make_pair(cnt + 1, pos - 1));
			isVisited[pos - 1] = true;
		}
		if (canMove(2 * pos)) {
			q.push(make_pair(cnt + 1, 2 * pos));
			isVisited[2 * pos] = true;
		}
		if (canMove(pos + 1)) {
			q.push(make_pair(cnt + 1, pos + 1));
			isVisited[pos + 1] = true;
		}
	}
}