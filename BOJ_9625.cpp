#include <iostream>
#define MAX 46
using namespace std;

int A[MAX];
int B[MAX];
int main() {
	int n;
	cin >> n;
	A[0] = 1;
	B[0] = 0;
	A[1] = 0;
	B[1] = 1;
	for (int i = 2; i <= n; i++) {
		A[i] = A[i - 1] + A[i - 2];
		B[i] = B[i - 1] + B[i - 2];
	}
	cout << A[n] << ' ' << B[n] << endl;
}