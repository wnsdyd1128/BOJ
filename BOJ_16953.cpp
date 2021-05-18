#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
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

ll A, B;
//map<ll, ll> DP;
//ll solution(ll n) {
//	if (n > B)
//		return INF; // 10^9, 실패 시 적당히 큰 수 반환
//	if (n == B)
//		return 0;
//	ll& ret = DP[n];
//	if (ret != 0)
//		return ret;
//	return ret = min(solution(n * 2), solution(n * 10 + 1)) + 1;
//}

ll solution() {
	ll ans = INF;
	queue<pair<ll, ll>> q;
	q.push(make_pair(A, 1));
	while (!q.empty()) {
		ll front = q.front().first;
		ll cnt = q.front().second;
		q.pop();
		if (front == B)
			ans = min(ans, cnt);
		if (front * 2 <= B)
			q.push(make_pair(front * 2, cnt + 1));
		if (front * 10 + 1 <= B)
			q.push(make_pair(front * 10 + 1, cnt + 1));
		cnt++;
	}
	if (ans == INF)
		return -1;
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> A >> B;
	cout << solution();
}