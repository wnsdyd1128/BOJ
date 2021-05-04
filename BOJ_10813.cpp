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
	int n, m;
	cin >> n >> m;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}
	for (int t = 0; t < m; t++) {
		int i, j;
		cin >> i >> j;
		swap(arr[i - 1], arr[j - 1]);
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}