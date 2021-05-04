#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	vector<int> v;
	cin >> n;
	for (int div = 2; n > 1; div++) {
		if (n == 1) {
			v.push_back(1);
			break;
		}
		while (n % div == 0) {
			n /= div;
			v.push_back(div);
		}
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << endl;
	}
}