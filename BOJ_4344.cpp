#include <iostream>
using namespace std;

int main() {
	int testcase, n;
	cin >> testcase;
	double* percent = new double[testcase];
	for (int i = 0; i < testcase; i++) {
		cin >> n;
		int* stu = new int[n];
		int sum = 0;
		double avg;
		int count = 0;
		for (int j = 0; j < n; j++) {
			cin >> stu[j];
			sum += stu[j];
		}
		avg = sum / n;
		for (int j = 0; j < n; j++) {
			if (stu[j] > avg) {
				count++;
			}
		}
		percent[i] = ((double)count / (double)n) * 100;
	}
	for (int i = 0; i < testcase; i++) {
		cout << fixed;
		cout.precision(3);
		cout << percent[i] << "%" << endl;
	}
}