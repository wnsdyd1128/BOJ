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
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	deque<int> d;
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		d.push_back(i);
	}
	int countOper = 0;
	for (int i = 1; i <= M; i++) {
		int input;
		cin >> input;
		deque<int>::iterator iter = find(d.begin(), d.end(), input);
		int idx = abs(distance(d.begin(), iter));
		if (d.size() / 2 < idx) {
			while (d.front() != input) {
				d.push_front(d.back());
				d.pop_back();
				countOper++;
			}
		}
		else {
			while (d.front() != input) {
				d.push_back(d.front());
				d.pop_front();
				countOper++;
			}
		}
		d.pop_front();
	}
	cout << countOper << endl;
}