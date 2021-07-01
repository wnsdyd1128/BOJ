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
int increase[100000];
int decrease[100000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vi v;
	int N;
	cin >> N;
	int ansIncrease = 1;
	int ansDecrease = 1;
	while (N--) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	int size = v.size();
	increase[0] = decrease[0] = 1;
	for (int i = 1; i < size; i++) {
		increase[i] = 1;
		if (v.at(i - 1) <= v.at(i)) {
			increase[i] = max(increase[i], increase[i - 1] + 1);
		}
		ansIncrease = max(ansIncrease, increase[i]);
	}
	for (int i = 1; i < size; i++) {
		decrease[i] = 1;
		if (v.at(i - 1) >= v.at(i)) {
			decrease[i] = max(decrease[i], decrease[i - 1] + 1);
		}
		ansDecrease = max(ansDecrease, decrease[i]);
	}
	cout << max(ansIncrease, ansDecrease) << endl;
}