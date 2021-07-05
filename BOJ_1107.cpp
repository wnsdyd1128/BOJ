#include <bits/stdc++.h>
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
bool brokenButton[10];
int check(int num) {
	if (!num) {
		return brokenButton[num] ? 0 : 1;
	}
	int len = 0;
	while (num > 0) {
		if (brokenButton[num % 10])
			return 0;
		len++;
		num /= 10;
	}
	return len;
}
int check(string str) {
	for (unsigned int i = 0; i < str.length(); i++) {
		if (brokenButton[static_cast<int>(str.at(i))])
			return 0;
	}
	return str.length();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(brokenButton, false, sizeof brokenButton);
	int N, M;
	cin >> N >> M;
	while (M--) {
		int input;
		cin >> input;
		brokenButton[input] = true;
	}
	int ans = abs(N - 100);
	for (int i = 0; i <= 1000000; i++) {
		int newChannel = i;
		int len = check(newChannel);
		//int len = check(to_string(newChannel));
		if (len > 0) {
			int cnt = abs(newChannel - N);
			ans = min(ans, len + cnt);
		}
	}
	cout << ans << endl;
}