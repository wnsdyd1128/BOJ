#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	vector<double> v;
	while (N--) {
		int edges;
		scanf("%d", &edges);
		int E = edges;
		vector<pair<double, double>> figure;
		while (E--) {
			int x, y;
			scanf("%d %d", &x, &y);
			figure.push_back(make_pair(x, y));
		}
		double maxDist = (figure[0].first * figure[0].first) + (figure[0].second * figure[0].second);
		for (int i = 1; i < figure.size(); i++) {
			double x2 = figure[i].first;
			x2 *= x2;
			double y2 = figure[i].second;
			y2 *= y2;
			maxDist = max(maxDist, x2 + y2);
		}
		v.push_back(maxDist);
	}
	sort(v.begin(), v.end());
	printf("%.2lf", v[K - 1]);
}