#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 100
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int N;
bool dist[MAX_N + 1][MAX_N + 1];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			cin >> dist[i][j];
		}
	}
	for(int k = 1; k <= N; k++) {
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				if(!dist[i][j] && dist[i][k] && dist[k][j])
					dist[i][j] = true;
			}
		}
	}
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << endl;
	}
}