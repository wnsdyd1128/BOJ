#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <sstream>
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
	map<string, int> m;
	vector<string> v;
	int N;
	cin >> N;
	while (N--) {
		string str;
		cin >> str;
		v.push_back(str);
	}
	int size = v.size();
	for (int i = 0; i < size; i++) {
		string name, extension;
		stringstream ss;
		ss.str(v.at(i));
		getline(ss, name, '.');
		getline(ss, extension);
		m[extension] = 0;
	}
	for (int i = 0; i < size; i++) {
		string name, extension;
		stringstream ss;
		ss.str(v.at(i));
		getline(ss, name, '.');
		getline(ss, extension);
		m[extension]++;
	}
	map<string, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++) {
		cout << iter->first << " " << iter->second << endl;
	}
}