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
	int N, M;
	cin >> N;
	map<int, int> m;
	vi list;
	while (N--) {
		int input;
		cin >> input;
		m[input]++;
	}
	cin >> M;
	while (M--) {
		int input;
		cin >> input;
		list.push_back(input);
	}
	int size = list.size();
	for (int i = 0; i < size; i++) {
		if (m.find(list.at(i)) == m.end()) // 찾지 못했을 때
			cout << "0 ";
		else
			cout << m[list.at(i)] << " ";
	}
}