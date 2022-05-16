#include <bits/stdc++.h>
#define endl '\n'
#define MAX_N 3000
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int, ii> iii;
bool isVisited[MAX_N + 1];
int N, K;
int bfs(int start) {
	priority_queue<ii, vii, greater<>> q;
	isVisited[start] = true;
	q.push(make_pair(0, start));
	while(!q.empty()) {
		auto& [cnt, cntT] = q.top();
		q.pop();
		for(int i = 0; i <= K; i++) {
			if (i > cntT || K - i > N - cntT)
				continue;
			int next = cntT + K - 2 * i;
			if (next == N)
				return cnt + 1;
			if(!isVisited[next]) {
				isVisited[next] = true;
				q.push(make_pair(cnt + 1, next));
			}
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	string str;
	cin >> str;
	int cnt = 0;
	for(auto i : str) {
		if (i == 'T')
			cnt++;
	}
	if (cnt == N)
		cout << 0 << endl;
	else
		cout << bfs(cnt) << endl;
}