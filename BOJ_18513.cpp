#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_X 200000000
#define _CRT_SECURE_NO_DEPRECATE
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int N, K;
set<int> isVisited;
bool canMove(int x) {
	if (isVisited.count(x) == 0)
		return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll ans = 0LL;
	queue<ii> q;
	cin >> N >> K;
	int cnt = 0;
	for(int i = 0; i < N; i++) {
		int x;
		cin >> x;
		q.push(make_pair(0, x));
		isVisited.insert(x);
	}
	bool flag = true;
	while(!q.empty()) {
		if (!flag)
			break;
		int size = q.size();
		while(size--) {
			int unhappiness = q.front().first;
			int pos = q.front().second;
			q.pop();
			if(canMove(pos - 1)) {
				q.push(make_pair(unhappiness + 1, pos - 1));
				ans += unhappiness + 1;
				isVisited.insert(pos - 1);
				cnt++;
			}
			if(cnt == K) {
				flag = false;
				break;
			}
			if(canMove(pos + 1)) {
				q.push(make_pair(unhappiness + 1, pos + 1));
				ans += unhappiness + 1;
				isVisited.insert(pos + 1);
				cnt++;
			}
			if (cnt == K) {
				flag = false;
				break;
			}
		}
	}
	cout << ans << endl;
}