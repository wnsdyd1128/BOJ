#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int num[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	int len = s.length();
	int ans = 1;
	for (int i = 0; i < len; i++) {
		int n = s.at(i) - '0';
		switch (n) {
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 7:
		case 8:
			if (num[n] == 0) {
				for (int i = 0; i < 10; i++) {
					num[i]++;
				}
				num[n]--;
				ans++;
			}
			else
				num[n]--;
			break;
		case 6:
			if (num[6] == 0) {
				if (num[9] == 0) {
					for (int i = 0; i < 10; i++) {
						num[i]++;
					}
					num[6]--;
					ans++;
				}
				else {
					num[9]--;
				}
			}
			else {
				num[6]--;
			}
			break;
		case 9:
			if (num[9] == 0) {
				if (num[6] == 0) {
					for (int i = 0; i < 10; i++) {
						num[i]++;
					}
					num[9]--;
					ans++;
				}
				else
					num[6]--;
			}
			else
				num[9]--;
		}
	}
	cout << ans << endl;
}