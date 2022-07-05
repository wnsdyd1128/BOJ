#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 200000
#define MAX_K 100000
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef tuple<int, int, int> tp;
typedef vector<tp> vtp;
int N, K;
bool isVisited[MAX_N + 1];
bool canMoveTo(int pos) {
	if (pos < 0 || pos > MAX_N || isVisited[pos])
		return false;
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> K;
	priority_queue<ii, vii, greater<>> q;
	q.push(make_pair(0, N));
	while (!q.empty()) {
		auto [cnt, pos] = q.top();
		if (pos == K) {
			cout << cnt << endl;
			return 0;
		}
		q.pop();
		if (canMoveTo(2 * pos)) {
			q.push(make_pair(cnt, 2 * pos));
			isVisited[2 * pos] = true;
		}
		if (canMoveTo(pos - 1)) {
			q.push(make_pair(cnt + 1, pos - 1));
			isVisited[pos - 1] = true;
		}
		if (canMoveTo(pos + 1)) {
			q.push(make_pair(cnt + 1, pos + 1));
			isVisited[pos + 1] = true;
		}

	}
}