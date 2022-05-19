#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int N, H, T;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> H >> T;
	priority_queue<int> q;
	while (N--) {
		int data;
		cin >> data;
		q.push(data);
	}
	bool flag = true;
	int cnt = 0;
	while (!q.empty()) {
		int height = q.top();
		if (height < H)
			break;
		if (cnt == T) {
			if (q.top() >= H) {
				flag = false;
				break;
			}
		}
		q.pop();
		if (height == 1)
			q.push(height);
		else
			q.push(height / 2);
		cnt++;
	}
	if (flag)
		cout << "YES" << endl << cnt << endl;
	else
		cout << "NO" << endl << q.top() << endl;
}