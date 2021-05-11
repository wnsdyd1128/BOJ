#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#define endl '\n'
#define INF 1000000000
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
	priority_queue<int> pq;
	int TC;
	cin >> TC;
	while (TC--) {
		int input;
		cin >> input;
		if (input == 0) {
			if (pq.empty()) {
				cout << "0" << endl;
			}
			else {
				cout << -(pq.top()) << endl;
				pq.pop();
			}
		}
		else {
			pq.push(-input);
		}
	}
}