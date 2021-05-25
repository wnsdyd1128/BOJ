#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <sstream>
#include <map>
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
	map<string, bool> list;
	int N;
	cin >> N;
	while (N--) {
		string name, command;
		cin >> name >> command;
		if (command == "enter") {
			list[name] = true;
		}
		if (command == "leave") {
			list[name] = false;
		}
	}
	map<string, bool>::iterator iter = list.end();
	while (true) {
		iter--;
		if (iter->second) {
			cout << iter->first << endl;
		}
		if (iter == list.begin())
			break;
	}
}