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
vii list;
ll cnt;
void Hanoi(int n, int from, int by, int to) {
	if (n == 1) {
		list.push_back(make_pair(from, to));
		cnt++;
		return;
	}
	Hanoi(n - 1, from, to, by);
	list.push_back(make_pair(from, to));
	cnt++;
	Hanoi(n - 1, by, from, to);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	Hanoi(n, 1, 2, 3);
	int size = list.size();
	cout << cnt << endl;
	for (int i = 0; i < size; i++) {
		cout << list.at(i).first << " " << list.at(i).second << endl;
	}
}