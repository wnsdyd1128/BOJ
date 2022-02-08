#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define _CRT_SECURE_NO_DEPRECATE
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC;
	cin >> TC;
	while (TC--) {
		string str;
		cin >> str;
		int start = 0;
		int end = str.length() - 1;
		int check = 0;
		while (start < end) {
			if (str[start] != str[end]) {
				if (check != 0) {
					check++;
					break;
				}
				check++;
				if (str[start + 1] == str[end] && str[start] == str[end - 1]) {
					int s = start, e = end;
					s++;
					while (s < e) {
						if (str[s] != str[e]) {
							check++;
							break;
						}
						s++;
						e--;
					}
					if (check == 1) {
						break;
					}
					s = start, e = end;
					e--;
					check = 1;
					while (s < e) {
						if (str[s] != str[e]) {
							check++;
							break;
						}
						s++;
						e--;
					}
					break;
				}
				else if (str[start + 1] == str[end]) {
					start++;
				}
				else if (str[start] == str[end - 1]) {
					end--;
				}
				else {
					check++;
					break;
				}
			}
			start++;
			end--;
		}
		cout << check << endl;
	}
}