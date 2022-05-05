#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 1004000
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
bool isPrime[MAX_N + 1];

bool isPalindrome(string str){
	int i = 0;
	int j = str.length() - 1;
	while(i < j) {
		if (str[i] != str[j])
			return false;
		i++;
		j--;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	memset(isPrime, true, sizeof isPrime);
	isPrime[0] = isPrime[1] = false;
	for(ll i = 2; i <= MAX_N; i++) {
		if(isPrime[i]) {
			for (ll j = i * i; j <= MAX_N; j += i)
				isPrime[j] = false;
		}
	}
	for (int i = n; ; i++) {
		if(isPrime[i] && isPalindrome(to_string(i))) {
			cout << i;
			break;
		}
	}
}