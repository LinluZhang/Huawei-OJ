#include "OJ.h"

bool IsArmstrongNumber(int n) {
    if(n < 2) {
        return false;
    }
    int sum = 0 ;
    int t = 0;
    int v = n;
    while(v != 0) {
        t = v%10;
        v /= 10;
        sum += t*t*t;
    }
    return sum == n;
}

/*
����: ��n(n �� 65536)���ڵ����а�ķ˹������
ԭ�ͣ�
    int CalcArmstrongNumber(int n);

���������
    int n: n �� 65536

����ֵ��
    n���ڵİ�ķ˹��������������
*/

int CalcArmstrongNumber(int n)
{
    /*������ʵ�ֹ���*/
    int result = 0;

    for(int i = 2; i <=n ;i++) {
        if(IsArmstrongNumber(i)) {
            result++;
        }

    }

    return result;
}


