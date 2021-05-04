#include <iostream>
#include <string>
#define MIN 9999999
using namespace std;

// flag :
// true -> white ฤฅวิ
// false -> black ฤฅวิ
int solution(int i, int j, int n, int m, string* s) {
	int white = 0, black = 0;
	string even = "WBWBWBWB";
	string odd = "BWBWBWBW";
	if (i + 8 > n || j + 8 > m) {
		return MIN;
	}
	for (int it1 = 0; it1 < 8; it1++) {
		for (int it2 = 0; it2 < 8; it2++) {
			if ((i + it1) % 2 == 0) {
				if (s[i + it1].at(j + it2) != even[it2]) {
					white++;
				}
			}
			else {
				if (s[i + it1].at(j + it2) != odd[it2]) {
					white++;
				}
			}
		}
	}
	even = "BWBWBWBW";
	odd = "WBWBWBWB";
	for (int it1 = 0; it1 < 8; it1++) {
		for (int it2 = 0; it2 < 8; it2++) {
			if ((i + it1) % 2 == 0) {
				if (s[i + it1].at(j + it2) != even[it2]) {
					black++;
				}
			}
			else {
				if (s[i + it1].at(j + it2) != odd[it2]) {
					black++;
				}
			}
		}
	}
	return min(white, black);
}
int main() {
	int n, m;
	int ans = MIN;
	cin >> n >> m;
	string* s = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> s[i];	
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans = min(ans, solution(i, j, n, m, s));
		}
	}
	cout << ans;
}