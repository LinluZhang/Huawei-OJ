#include <stdlib.h>
#include "oj.h"

unsigned int power(unsigned int x, unsigned int y) {
    unsigned int rst = 1;
    for(int i = 0; i < y; i++) {
        rst *= x;
    }

    return rst;
}

// ���ܣ��ж����� nValue �Ƿ�Ϊˮ�ɻ���
// ���룺 nValueΪ������
// �������
// ���أ��������Ϊˮ�ɻ���������1�����򷵻�0
unsigned int IsDaffodilNum(unsigned int  nValue) {

    unsigned int cnt = 0;
    unsigned int v = nValue;
    unsigned int t = 0;

    // ��nValue�Ƕ���λ��
    do {
        cnt++;
        v /= 10;
    } while(v != 0);

    v = nValue;

    do {
        unsigned int n = v % 10;
        t += power(n, cnt);
        v /= 10;
    } while(v != 0);

    if(t == nValue) {
        return 1;
    }


    return 0;
}
