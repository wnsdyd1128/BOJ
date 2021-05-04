#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v(8);
	for (int i = 0; i < 8; i++) {
		cin >> v[i];
	}
	vector<int> sorted = v;
	sort(sorted.begin(), sorted.end());
	if (sorted == v) {
		cout << "ascending";
	}
	else {
		sort(sorted.begin(), sorted.end(), greater<>());
		if (sorted == v) {
			cout << "descending";
		}
		else {
			cout << "mixed";
		}
	}
}