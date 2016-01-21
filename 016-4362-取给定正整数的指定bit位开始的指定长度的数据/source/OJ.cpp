
#include "OJ.h"

/*
Description
         ȡ������������ָ��bitλ��ʼ��ָ�����ȵ����ݡ�bitλ���������0��ʼ���㡣
Prototype
         unsigned int GetBitsValue(unsigned int input, unsigned int startbit, unsigned int bitlen)
Input Param
         input      ���������
         startbit   ��Ҫ��ȡ�Ŀ�ʼbit
         bitlen     ��Ҫ��ȡ��bit����
Output Param
         ��
Return Value
		 ��Ӧ��bitȡֵ
*/

unsigned int GetBitsValue(unsigned int input, unsigned int startbit, unsigned int bitlen) {

    unsigned int mask = 0;
    unsigned int endbit =startbit + 1 - bitlen;
    mask = (~mask) << (bitlen);

    input = input >> endbit;
    input = input & (~mask);

    return input;
}
