#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 5000
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
vector<vii> v;
bool isVisited[MAX_N + 1];
ll solution(int vertex) {
	ll ans = 0LL;
	isVisited[vertex] = true;
	for(auto& i : v[vertex]) {
		if (!isVisited[i.first])
			ans = max(ans, solution(i.first) + i.second);
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	v.resize(N + 1);
	N--;
	while(N--) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back(make_pair(to, cost));
		v[to].push_back(make_pair(from, cost));
	}
	cout << solution(1) << endl;

}