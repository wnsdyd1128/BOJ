#include <iostream>
#include <cstdio>
#pragma warning(disable:4996)
using namespace std;

long long int Interval(long long int a, long long int b) {
	return (b * (b + 1)) / 2 - (a * (a - 1)) / 2;
}
int main() {
	long long int a, b, sum;
	scanf("%lld %lld", &a, &b);
	if (a > b) {
		sum = Interval(b, a);
	}
	else {
		sum = Interval(a, b);
	}
	
	printf("%lld", sum);
}