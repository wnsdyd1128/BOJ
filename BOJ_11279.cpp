#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<int> pq;
	int n;
	cin >> n;
	while (n--) {
		int input;
		cin >> input;
		if (input == 0) {
			if (pq.empty()) {
				cout << "0" << endl;
			}
			else {
				cout << pq.top() << endl;
				pq.pop();
			}
		}
		else {
			pq.push(input);
		}
	}
}