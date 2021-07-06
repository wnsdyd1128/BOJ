#include <bits/stdc++.h>
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
bool canNotSelect[10];
int arr[10];

void Solution(int idx, int start, int n, int m) {
	if (idx == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << endl;
		return;
	}
	for (int i = start; i <= n; i++) {
		if (canNotSelect[i])
			continue;
		arr[idx] = i;
		canNotSelect[i] = true;
		Solution(idx + 1, i + 1, n, m);
		canNotSelect[i] = false;
	}
	/*for (int i = 1; i <= n; i++) {
		if (canNotSelect[i])
			continue;
		arr[idx] = i;
		for (int j = 1; j <= i; j++) {
			canNotSelect[j] = true;
		}
		Solution(idx + 1, n, m);
		for (int j = 1; j <= i; j++) {
			canNotSelect[j] = false;
		}
	}*/
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	Solution(0, 1, n, m);
}