#include <iostream>
#define MAX 10001
using namespace std;

int sorted[MAX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		sorted[input]++;
	}
	for (int i = 0; i < MAX; i++) {
		if (sorted[i] != 0) {
			for (int j = 0; j < sorted[i]; j++) {
				cout << i << '\n';
			}
		}
	}
}