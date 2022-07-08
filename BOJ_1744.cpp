#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef tuple<int, int, int> tp;
typedef vector<tp> vtp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	cin >> N;
	vi v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	vi positive, negative, one, zero;
	for (auto i : v) {
		if (i > 1)
			positive.push_back(i);
		else if (i == 1)
			one.push_back(1);
		else if (i == 0)
			zero.push_back(0);
		else
			negative.push_back(i);
	}
	sort(positive.begin(), positive.end(), greater<>());
	sort(negative.begin(), negative.end());
	int ans = 0;
	int pos = 0;
	int neg = 0;
	for (; pos + 1 < positive.size(); pos += 2)
		ans += positive[pos] * positive[pos + 1];
	if (pos == positive.size() - 1)
		ans += positive[pos];
	for (; neg + 1 < negative.size(); neg += 2)
		ans += negative[neg] * negative[neg + 1];
	if (neg == negative.size() - 1) {
		if (zero.empty())
			ans += negative[neg];
	}
	ans += one.size();
	cout << ans << endl;
}