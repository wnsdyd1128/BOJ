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
bool isBigger(ii criteria, ii subject) {
	if (criteria.first > subject.first && criteria.second > subject.second)
		return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vii v;
	vi rank;
	int N;
	cin >> N;
	while (N--) {
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	size_t size = v.size();
	for (int i = 0; i < size; i++) {
		int cnt = 0;
		for (int j = 0; j < i; j++) {
			if (isBigger(v.at(j), v.at(i))) {
				cnt++;
			}
		}
		for (int j = i + 1; j < size; j++) {
			if (isBigger(v.at(j), v.at(i))) {
				cnt++;
			}
		}
		rank.push_back(cnt + 1);
	}
	size = rank.size();
	for (int i = 0; i < size; i++) {
		cout << rank.at(i) << ' ';
	}
}