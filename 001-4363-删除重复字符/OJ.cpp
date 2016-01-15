
#include "OJ.h"

/*
Description
         ����һ���ַ��������ַ��������к�ǰ���ظ�������ַ�ɾ���������ַ�����������������ַ�������Ҫ��֤�ַ����ֵ��Ⱥ�˳��
Prototype
         int GetResult(const char *input, char *output)
Input Param
         input     ������ַ���
Output Param
         output    ������ַ���
Return Value
         0         �ɹ�
         -1        ʧ�ܼ��쳣
*/
int GetResult(const char *input, char *output) {

    if(input == '\0' || output == '\0') {
        return - 1;
    }

    for(int i = 0; *(input + i) != '\0'; i++) {
        bool appear = false;
        for(int j = 0; j < i; j++) {
            if(*(input + j) == *(input + i)) {
                appear = true;
                break;
            }
        }

        if(!appear) {
            *output = *(input + i);
            output++;
        }
    }

    *output = '\0';

    return 0;
}


