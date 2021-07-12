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
vi v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, s;
	int cnt = 0;
	cin >> N >> s;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	for (int i = 1; i < (1 << N); i++) {
		int sum = 0;
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) { // j번째 원소가 포함되었는지 검사
				sum += v.at(j);
			}
		}
		if (sum == s) {
			cnt++;
		}
	}
	cout << cnt << endl;

}