#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define _CRT_SECURE_NO_DEPRECATE
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<char, int> ci;
typedef vector<ci> vci;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
void solution(map<char, int>& m, const string& str) {
	for (int i = 0; i < str.length(); i++) {
		m[str[i]] += pow(10, str.length() - i - 1);
	}
}

bool compare(ci a, ci b) {
	return a.second > b.second;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	map<char, int> m;
	vci v;
	vector<string> vs;
	while (N--) {
		string str;
		cin >> str;
		solution(m, str);
		vs.push_back(str);
	}
	for (auto i : m) {
		v.push_back(make_pair(i.first, i.second));
	}
	sort(v.begin(), v.end(), compare); // second에 대한 내림차순 정렬
	int digit = 9;
	for (int i = 0; i < v.size(); i++) {
		m[v[i].first] = digit;
		digit--;
	}
	int ans = 0;
	for (int i = 0; i < vs.size(); i++) {
		for (int j = 0; j < vs[i].length(); j++) {
			vs[i][j] = m[vs[i][j]] + '0';

		}
	}
	for (int i = 0; i < vs.size(); i++) {
		ans += stoi(vs[i]);
	}
	cout << ans << endl;
}