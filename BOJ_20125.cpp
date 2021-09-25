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

vector<string> vs;
int n;
bool isHeart(int x, int y) {
	if (x <= 0 || y <= 0 || x + 1 >= n || y + 1 >= n)
		return false;
	if (vs[x][y] == '*' && vs[x - 1][y] == '*' && vs[x + 1][y] == '*' && vs[x][y - 1] == '*' && vs[x][y + 1] == '*')
		return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int N = n;
	while (N--) {
		string str;
		cin >> str;
		vs.push_back(str);
	}
	ii heart;
	for (int i = 0; i < vs.size(); i++) {
		for (int j = 0; j < vs[i].length(); j++) {
			if (isHeart(i, j)) {
				heart.first = i;
				heart.second = j;
			}
		}
	}

	//leftArm
	int leftArm = 0;
	int rightArm = 0;
	for (int j = 0; j < heart.second; j++) {
		if (vs[heart.first][j] == '*')
			leftArm++;
	}
	for (int j = heart.second + 1; j < n; j++) {
		if (vs[heart.first][j] == '*')
			rightArm++;
		else
			break;
	}

	int waist = 0;
	for (int i = heart.first + 1; i < n; i++) {
		if (vs[i][heart.second] == '*') {
			waist++;
		}
		else
			break;
	}
	int leftLeg = 0;
	int rightLeg = 0;
	for (int i = heart.first + waist + 1; i < n; i++) {
		if (vs[i][heart.second - 1] == '*') {
			leftLeg++;
		}
		else
			break;
	}
	for (int i = heart.first + waist + 1; i < n; i++) {
		if (vs[i][heart.second + 1] == '*') {
			rightLeg++;
		}
		else
			break;
	}
	cout << heart.first + 1 << ' ' << heart.second + 1 << endl;
	cout << leftArm << ' ' << rightArm << ' ' << waist << ' ' << leftLeg << ' ' << rightLeg << endl;
}