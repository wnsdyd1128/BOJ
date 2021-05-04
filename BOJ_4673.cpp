//BOJ 4673 �����ѹ�

#include<iostream>
#include<cstdio>
#define N 10001 //�迭 arr[1 ~ 10000] ���� �̹Ƿ� 10001.

using namespace std;
bool arr[N];

//�����ѹ� �Ǻ� �Լ�.
int solution(int n) {
    int sum = n;    //�ڱ� �ڽ��� ���� �����ְ�

    while (1) {   // �� �ڸ����� ���ڸ� ���ؾ��ϹǷ� 1�� �ڸ��� ��� �����ش�.

        if (n == 0) break; //0�� �Ǹ� break
        sum += n % 10;      //1�� �ڸ� �����ֱ�
        n = n / 10;         //���ڸ��� ���ֱ�

    }

    return sum;
}


int main(void) {

    for (int i = 1; i < N; i++) {
        int idx = solution(i);

        if (idx <= N) {
            arr[idx] = true;    //�����ѹ� �ƴ� �� true �� ����
        }

    }

    //���
    for (int i = 1; i < N; i++) {
        if (!arr[i]) printf("%d\n", i);
    }

    return 0;
}