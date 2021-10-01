#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX 200000
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int dist[MAX + 1];
int path[MAX + 1];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	queue<int> q;
	q.push(N);
	memset(dist, -1, sizeof dist);
	dist[N] = 0;
	while (!q.empty()) {
		int pos = q.front();
		q.pop();
		if (pos - 1 >= 0) {
			if (dist[pos - 1] == -1) {
				dist[pos - 1] = dist[pos] + 1;
				q.push(pos - 1);
				path[pos - 1] = pos;
			}
		}
		if (pos + 1 <= MAX) {
			if (dist[pos + 1] == -1) {
				dist[pos + 1] = dist[pos] + 1;
				q.push(pos + 1);
				path[pos + 1] = pos;
			}

		}
		if (2 * pos <= MAX) {
			if (dist[pos * 2] == -1) {
				dist[pos * 2] = dist[pos] + 1;
				q.push(pos * 2);
				path[pos * 2] = pos;
			}
		}
	}
	cout << dist[K] << endl;
	stack<int> s;
	int cur = K;
	while (cur != N) {
		s.push(cur);
		cur = path[cur];
	}
	s.push(N);
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
}