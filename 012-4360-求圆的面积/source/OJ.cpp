#include <stdlib.h>
#include <string.h>
#include "oj.h"


/*
����:

����:

���:	arrValue:�洢���صķ��Ϸ�Χ֮�ڵ�Բ������ڴ��ں������Ѿ�����
		nValue:�������������

����:

*/

void OutputRotundityArea(float *arrValue,int &nValue) {
    float PI = 3.14;

    nValue = 0;
    float v;
    for(int i = 1; i <= 10; i++) {
        v = i*i*PI;
        if(v >= 40 && v <= 90) {
            arrValue[nValue] = v;
            nValue++;
        }
    }
}
