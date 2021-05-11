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
	queue<int> q, josep;
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	int iter = 1;
	while (!q.empty()) {
		if (iter == k) {
			josep.push(q.front());
			q.pop();
			iter = 1;
		}
		else {
			int temp = q.front();
			q.pop();
			q.push(temp);
			iter++;
		}
	}
	cout << "<";
	while (!josep.empty()) {
		if (josep.size() == 1) {
			break;
		}
		cout << josep.front() << ", ";
		josep.pop();
	}
	cout << josep.front() <<">" << endl;

}