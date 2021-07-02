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
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	map<int, int> m;
	vi v;
	vi mode;
	int N;
	double sum = 0.0;
	int cnt = -1;
	int common;
	cin >> N;
	while (N--) {
		int input;
		cin >> input;
		v.push_back(input);
		m[input]++;
		sum += input;
	}
	sort(v.begin(), v.end());
	int range = v.at(v.size() - 1) - v.at(0);
	int mid = v.at(v.size() / 2);
	int mean = static_cast<int>(floor(sum / v.size() + 0.5));
	map<int, int>::iterator iter = m.begin();
	for (; iter != m.end(); iter++) {
		if (iter->second > cnt) {
			cnt = iter->second;
			mode.clear();
			mode.push_back(iter->first);
		}
		else if (iter->second == cnt) {
			mode.push_back(iter->first);
		}
	}
	sort(mode.begin(), mode.end());
	if (mode.size() >= 2)
		common = mode.at(1);
	else
		common = mode.at(0);
	cout << mean << endl << mid << endl << common << endl << range;

}