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
bool compare(ii pair1, ii pair2) {
	if (pair1.first == pair2.first)
		return pair1.second < pair2.second;
	return pair1.first < pair2.first;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vii list;
	while (N--) {
		int x, y;
		cin >> x >> y;
		list.push_back(make_pair(x, y));
	}
	sort(list.begin(), list.end(), compare);
	int length = list.size();
	for (int i = 0; i < length; i++) {
		cout << list.at(i).first << " " << list.at(i).second << endl;
	}
}