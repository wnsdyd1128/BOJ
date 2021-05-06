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
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	int m;
	cin >> m;
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		int input;
		cin >> input;
		if (binary_search(v.begin(), v.end(), input)) {
			cout << "1" << endl;	
		}
		else {
			cout << "0" << endl;
		}
	}
}