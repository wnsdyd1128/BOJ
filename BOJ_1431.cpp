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
bool compare(string a, string b) {
	if (a.length() != b.length())
		return a.length() < b.length();
	int sumOfA = 0;
	int sumOfB = 0;
	for (int i = 0; i < a.length(); i++) {
		if (isdigit(a.at(i))) {
			sumOfA += a.at(i) - '0';
		}
	}
	for (int i = 0; i < b.length(); i++) {
		if (isdigit(b.at(i))) {
			sumOfB += b.at(i) - '0';
		}
	}
	if (sumOfA != sumOfB)
		return sumOfA < sumOfB;
	return a < b;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<string> v;
	while (N--) {
		string str;
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << endl;
	}
}