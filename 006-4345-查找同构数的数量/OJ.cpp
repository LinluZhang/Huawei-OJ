#include <math.h>
#include "OJ.h"


bool IsSameConstructNum(int n) {
    if (n < 1) {
        return false;
    }

    long m = n*n;

    while(n != 0) {
        if(n%10 == m%10) {
            n /= 10;
            m /= 10;
        } else {
            return false;
        }
    }

    return true;
}
/*
����:�ҳ�1��n֮��ͬ�����ĸ���
���룺
    int n������1��n֮���ȫ��ͬ����
���أ�
    int��1��n֮��ͬ�����ĸ���
*/
int SearchSameConstructNum(int n) {

    int result = 0;

    for(int i = 1; i <= n; i++) {
        if(IsSameConstructNum(i)) {
            result++;
        }
    }


    return result;
}
