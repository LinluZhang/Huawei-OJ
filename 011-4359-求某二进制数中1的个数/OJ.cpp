
#include "OJ.h"

/*
Description
         ����һ��unsigned int�͵�����������������Ʊ�ʾ�С�1���ĸ�����Ҫ���㷨��ִ��Ч�ʾ����ܵظߡ�
Prototype
         int GetCount(unsigned int num)
Input Param
         num     ������������
Output Param
         ��
Return Value
         ����1�ĸ���
*/
int GetCount(unsigned int num) {

    // һ��unsigned intռ����λ
    unsigned int bitNum = 8*sizeof(unsigned int);
    int rst = 0;

    while(num != 0) {
        rst += num & 1;
        num >>= 1;
    }

    return rst;
}
