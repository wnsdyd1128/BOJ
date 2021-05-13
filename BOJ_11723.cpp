#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#define endl '\n'
#define INF 1000000000
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int bitMask[21];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC;
	cin >> TC;
	while (TC--) {
		string s;
		cin >> s;
		if (s == "add") {
			int x;
			cin >> x;
			bitMask[x]++;
		}
		if (s == "remove") {
			int x;
			cin >> x;
			if (bitMask[x])
				bitMask[x] = 0;
		}
		if (s == "check") {
			int x;
			cin >> x;
			if (bitMask[x])
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		if (s == "toggle") {
			int x;
			cin >> x;
			if (bitMask[x])
				bitMask[x] = 0;
			else
				bitMask[x]++;
		}
		if (s == "all") {
			for (int i = 1; i <= 20; i++)
				bitMask[i]++;
		}
		if (s == "empty") {
			for (int i = 1; i <= 20; i++)
				bitMask[i] = 0;
		}
	}
}