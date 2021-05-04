#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	vector<int> v;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= v[i]; j++) {
			cout << "=";
		}
		cout << endl;
	}
}