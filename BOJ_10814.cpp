#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#define endl '\n'
using namespace std;

bool compare(pair<int, pair<string, int>> i, pair<int, pair<string, int>> j) {
	if (i.first == j.first) {
		return i.second.second < j.second.second;
	}
	return i.first < j.first;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, pair<string, int>>> member;
	for (int i = 0; i < n; i++) {
		int age;
		string name;
		cin >> age >> name;
		member.push_back(make_pair(age, make_pair(name, i)));
	}
	sort(member.begin(), member.end(), compare);
	vector<pair<int, pair<string, int>>>::iterator it = member.begin();
	for (; it != member.end(); it++) {
		cout << (*it).first << " " << (*it).second.first << endl;
	}
}