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
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	map<ll, int> m;
	while (N--) {
		ll input;
		cin >> input;
		if (m.find(input) != m.end())
			m[input]++;
		else
			m[input] = 1;
	}
	map<ll, int>::iterator iter;
	ll ans = 0;
	int _max = -1;
	for (iter = m.begin(); iter != m.end(); iter++) {	
		if (_max < (*iter).second) {
			_max = (*iter).second;
			ans = (*iter).first;
		}
	}
	cout << ans << endl;
}