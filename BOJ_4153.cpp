#include <iostream>
using namespace std;

bool isRightTriangle(int hypotenuse, int side1, int side2) {
	hypotenuse *= hypotenuse;
	side1 *= side1;
	side2 *= side2;
	return hypotenuse == side1 + side2 ? true : false;
}
int main() {
	int a, b, c;
	while(true) {
		cin >> a >> b >> c;
		if (a + b + c == 0) {
			break;
		}
		if (isRightTriangle(a, b, c) || isRightTriangle(b, a, c) || isRightTriangle(c, a, b)) {
			cout << "right" << endl;
		}
		else {
			cout << "wrong" << endl;
		}
	}
}