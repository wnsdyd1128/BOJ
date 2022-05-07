#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_M 100000
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
bool isVisited[MAX_M + 1];
vi v[MAX_M + 1];
int N, M;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int P;
	cin >> N >> M >> P;
	for(int i = 0; i < N; i++) {
		int f, h;
		cin >> f >> h;
		if(v[h].empty())
			v[h].push_back(f);
	}
	queue<int> q;
	q.push(P);
	isVisited[P] = true;
	int ans = 0;
	while(!q.empty()) {
		int vertex = q.front();
		q.pop();
		for(auto i : v[vertex]) {
			if(isVisited[i]) {
				ans = -1;
				break;
			}
			else {
				q.push(i);
				isVisited[i] = true;
				ans++;
			}
		}
	}
	cout << ans << endl;
	
}