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

    int idx = 0;
    float v;
    for(int i = 0; i < nValue; i++) {
        v = PI*arrValue[i]*arrValue[i];
        //if(v >= 40 && v <= 90) {
            arrValue[i] = v;
            idx++;
        //}
    }
}
