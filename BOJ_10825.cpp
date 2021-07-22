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
class Student {
public:
	string name;
	int kor;
	int eng;
	int mat;
	Student(string _name, int _kor, int _eng, int _mat) : name(_name), kor(_kor), eng(_eng), mat(_mat) {}
};
bool compare(Student stu1, Student stu2) {
	if (stu1.kor != stu2.kor)
		return stu1.kor > stu2.kor;
	if (stu1.eng != stu2.eng)
		return stu1.eng < stu2.eng;
	if (stu1.mat != stu2.mat)
		return stu1.mat > stu2.mat;
	return stu1.name < stu2.name;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<Student> v;
	int N;
	cin >> N;
	while (N--) {
		string name;
		int kor, eng, mat;
		cin >> name >> kor >> eng >> mat;
		v.push_back(Student(name, kor, eng, mat));
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i).name << endl;
	}
}