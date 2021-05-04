#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int arr[9];
	int sum = 0;
	int idx1, idx2;
	vector<int> v;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - (arr[i] + arr[j]) == 100) {
				idx1 = i;
				idx2 = j;
				break;
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		if (i == idx1 || i == idx2) {
			continue;
		}
		v.push_back(arr[i]);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << endl;
	}
}