#include <iostream>
using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	int d1 = x;
	int d2 = y;
	int d3 = w - x;
	int d4 = h - y;
	cout << min(d1, min(d2, min(d3, d4)));
}