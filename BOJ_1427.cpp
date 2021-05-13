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
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	cin >> str;
	vi sorted;
	int length = str.length();
	for (int i = 0; i < length; i++) {
		sorted.push_back(static_cast<int>(str.at(i) - '0'));
	}
	sort(sorted.begin(), sorted.end(), greater<>());
	int size = sorted.size();
	for (int i = 0; i < size; i++)
		cout << sorted.at(i);
}