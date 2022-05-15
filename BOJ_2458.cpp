#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 500
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
	int M;
	cin >> N >> M;
	vector<vi> dist(MAX_N + 1, vi(MAX_N + 1, INF));
	for (int i = 1; i <= N; i++)
		dist[i][i] = 0;
	while(M--) {
		int from, to;
		cin >> from >> to;
		dist[from][to] = 1; // dist[from][to] := from < to
	}
	for(int k = 1; k <= N; k++) {
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= N; i++) {
		int cnt = 0;
		for(int j = 1; j <= N; j++) {
			if (dist[i][j] != INF || dist[j][i] != INF)
				cnt++;
		}
		if (cnt == N)
			ans++;
	}
	cout << ans << endl;
}