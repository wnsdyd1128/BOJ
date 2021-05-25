#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
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
	int N;
	cin >> N;
	priority_queue<ii, vii, greater<>> pq;
	while (N--) {
		int input;
		cin >> input;
		if (input == 0) {
			if (pq.empty()) {
				cout << "0" << endl;
			}
			else {
				cout << pq.top().first * pq.top().second << endl;
				pq.pop();
			}
		}
		else {
			int isNegative = ((input < 0) ? -1 : 1);
			pq.push(make_pair(abs(input), isNegative));
		}
	}
}