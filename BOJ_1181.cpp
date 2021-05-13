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
bool compare(string str1, string str2) {
	if (str1.length() == str2.length())
		return str1 < str2;
	return str1.length() < str2.length();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<string> list;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		list.push_back(str);
	}
	sort(list.begin(), list.end(), compare);
	list.erase(unique(list.begin(), list.end()), list.end());
	for (int i = 0; i < list.size(); i++) {
		cout << list.at(i) << endl;
	}
}