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
bool solution(vi& permutation) {
	int i = permutation.size() - 1;
	while (i > 0 && permutation.at(i - 1) >= permutation.at(i)) {
		i--;
	}
	if (i <= 0)
		return false;
	int j = permutation.size() - 1;
	while (permutation.at(j) <= permutation.at(i - 1)) {
		j--;
	}
	swap(permutation.at(j), permutation.at(i - 1));
	j = permutation.size() - 1;
	while (i < j) {
		swap(permutation.at(i), permutation.at(j));
		j--;
		i++;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vi v;
	while (N--) {
		int input;
		cin >> input;
		v.push_back(input);
	}
	if (solution(v)) {
		for (int i = 0; i < v.size(); i++) {
			cout << v.at(i) << ' ';
		}
	}
	else
		cout << "-1";

}