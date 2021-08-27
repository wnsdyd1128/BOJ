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
struct Student {
	string name;
	int day;
	int month;
	int year;
};
typedef Student Stu;

bool compare(Stu s1, Stu s2) {
	if (s1.year == s2.year) {
		if (s1.month == s2.month)
			return s1.day > s2.day;
		return s1.month > s2.month;
	}
	return s1.year > s2.year;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<Stu> v;
	int TC;
	cin >> TC;
	while (TC--) {
		string str;
		int day, month, year;
		cin >> str >> day >> month >> year;
		v.push_back({ str, day, month, year });
	}
	sort(v.begin(), v.end(), compare);
	cout << v[0].name << endl << v[v.size() - 1].name << endl;
}