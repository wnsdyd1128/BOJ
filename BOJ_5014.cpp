#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_F 1000000
#define _CRT_SECURE_NO_DEPRECATE
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
bool isVisited[MAX_F + 5];
int F, S, G, U, D;
bool canMove(int cur) {
	if (1 <= cur && cur <= F && !isVisited[cur])
		return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<ii, vii, greater<>> q;
	cin >> F >> S >> G >> U >> D;
	q.push({ 0,  S });
	bool flag = true;
	while(!q.empty()) {
		int button = q.top().first;
		int floor = q.top().second;
		q.pop();
		if(floor == G) {
			cout << button << endl;
			flag = false;
			break;
		}
		if(canMove(floor + U)) {
			isVisited[floor + U] = true;
			q.push(make_pair(button + 1, floor + U));
		}
		if(canMove(floor - D)) {
			isVisited[floor - D] = true;
			q.push(make_pair(button + 1, floor - D));
		}
	}
	if (flag)
		cout << "use the stairs" << endl;
}