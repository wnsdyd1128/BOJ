// BOJ.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

inline int OnetoN(int n) {
    return (n * (n + 1)) / 2;
}

int main() {
    int n;
    cin >> n;
    int* sum = new int[n];
    for (int i = 0; i < n; i++) {
        sum[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int arr[81];
        arr[0] = -1;
        int j = 1;
        int length = 1;
        char str[81];
        cin >> str;
        char* ptr = new char[strlen(str) + 1];
        strcpy_s(ptr, strlen(str) + 1, str);
        for (int i = 0; i < strlen(str) + 1; i++) {
            if (ptr[i] == 'X' || ptr[i] == '\0') {
                arr[j] = i;
                j++;
                length++;
            }
        }
        for (int k = 0; k < length - 1; k++) {
            sum[i] += OnetoN(arr[k + 1] - arr[k] - 1);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << sum[i] << endl;
    }
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
