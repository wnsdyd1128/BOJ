#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#define endl '\n'
#define INF 1000000000
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;
int solution(vi priorities, int location) {
    int answer = 0;
    int length = priorities.size();
    priority_queue<int> q;
    for (int i = 0; i < length; i++) {
        q.push(priorities.at(i));
    }
    int identifier = location;
    while (!priorities.empty()) {
        if (q.top() == priorities.front()) {
            q.pop();
            answer++;
            length--;
            if (!identifier) {
                break;
            }
        }
        else {
            priorities.push_back(priorities.front());
        }
        priorities.erase(priorities.begin());
        if (!identifier) {
            identifier = length - 1;
        }
        else identifier--;
    }
    return answer;
}
int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, m;
        cin >> n >> m;
        vi priorities;
        for (int i = 0; i < n; i++) {
            int input;
            cin >> input;
            priorities.push_back(input);
        }
        cout << solution(priorities, m) << endl;
    }
}