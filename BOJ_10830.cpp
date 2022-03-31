#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 5
#define MOD 1000
#define _CRT_SECURE_NO_DEPRECATE
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;

class Matrix {
private:
	size_t size;
	ll arr[MAX_N + 1][MAX_N + 1];
public:
	Matrix(size_t _size) : size(_size) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				arr[i][j] = 0;
			}
		}
	}
	
	size_t getSize() {
		return size;
	}
	
	void convertToIdentity() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (i == j)
					arr[i][j] = 1;
				else
					arr[i][j] = 0;
			}
		}
	}
	void set(int i, int j, int data) {
		arr[i][j] = data;
	}
	Matrix operator=(Matrix& rhs) {
		size_t size = rhs.size;
		Matrix ret(size);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				ret.arr[i][j] = rhs.arr[i][j];
			}
		}
		return ret;
	}
	Matrix operator*(Matrix& rhs) {
		Matrix ret(size);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				for (int k = 0; k < size; k++) {
					ret.arr[i][j] += this->arr[i][k] * rhs.arr[k][j];
				}
				ret.arr[i][j] %= MOD;
			}
		}
		return ret;
	}
	friend ostream& operator<<(ostream& os, Matrix rhs);
};

ostream& operator<<(ostream& os, Matrix rhs) {
	for (int i = 0; i < rhs.size; i++) {
		for (int j = 0; j < rhs.size; j++) {
			os << rhs.arr[i][j] << ' ';
		}
		os << endl;
	}
	return os;
}
Matrix identityMatrix(size_t size) {
	Matrix m(size);
	m.convertToIdentity();
	return m;
}

Matrix solution(Matrix& m, ll n) {
	if (n == 0)
		return identityMatrix(m.getSize());
	if (n % 2 == 1)
		return solution(m, n - 1) * m;
	Matrix half = solution(m, n / 2);
	return half * half;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	ll B;
	cin >> N >> B;
	Matrix m(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int input;
			cin >> input;
			m.set(i, j, input);
		}
	}
	cout << solution(m, B) << endl;
}