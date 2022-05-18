#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	priority_queue<int, vi, greater<>> q;
	cin >> N;
	while (N--) {
		int data;
		cin >> data;
		q.push(data);
	}
	ll ans = 0LL;
	while (q.size() >= 2) {
		int lhs = q.top();
		q.pop();
		int rhs = q.top();
		q.pop();
		ans += lhs + rhs;
		q.push(lhs + rhs);
	}
	cout << ans << endl;
}