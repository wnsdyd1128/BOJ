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
	int n;
	cin >> n;
	queue<int> q;
	vi v;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (n--) {
		v.push_back(q.front());
		q.pop();
		if (q.empty()) {
			break;
		}
		q.push(q.front());
		q.pop();
	}
	int length = v.size();
	for (int i = 0; i < length - 1; i++) {
		cout << v.at(i) << " ";
	}
	cout << v.at(length - 1) << endl;
}