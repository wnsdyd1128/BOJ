#include <iostream>
#include <stack>
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	stack<int> s;
	int k, sum = 0;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int n;
		cin >> n;
		if (n != 0) {
			s.push(n);
		}
		else {
			s.pop();
		}
	}
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}
	cout << sum;
}