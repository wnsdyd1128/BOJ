#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, m;
	int largest = -1;
	vector<int> card;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		card.push_back(num);
	}
	int length = card.size();
	for (int i = 0; i < length; i++) {
		for (int j = i + 1; j < length; j++) {
			for (int k = j + 1; k < length; k++) {
				int sum = card[i] + card[j] + card[k];
				if (sum <= m) {
					largest = max(largest, sum);
				}
			}
		}
	}
	cout << largest;
}