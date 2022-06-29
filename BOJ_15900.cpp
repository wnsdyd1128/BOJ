#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 500000
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int N;
ll cnt;
bool isVisited[MAX_N + 1];
vi v[MAX_N + 1]; // v[i] := i의 자식 리스트
void dfs(int vertex, ll d) {
	if (v[vertex].size() == 1)
		cnt += d;
	isVisited[vertex] = true;
	for (auto i : v[vertex]) {
		if (!isVisited[i])
			dfs(i, d + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;
	int M = N - 1;
	while (M--) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
	dfs(1, 0);
	if (cnt % 2 == 1)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}