
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

    int chars[255];
    // �����ʼ��
    int i;
    for(int i = 0; i < 255; i++) {
        chars[i] = 0;
    }

    for(i = 0; *(input + i) != '\0'; i++) {
        // ��û�д����*pointer�ַ�
        if(chars[(*(input + i))] == 0) {
            *output = *(input + i);
            chars[(*(input + i))]++;
            output++;
        }
    }

    *output = '\0';

    return 0;
}

int Sovle1(const char *input, char *output) {

    if(input == '\0' || output == '\0') {
        return - 1;
    }

    int chars[255];
    // �����ʼ��
    int i;
    for(int i = 0; i < 255; i++) {
        chars[i] = 0;
    }

    for(i = 0; *(input + i) != '\0'; i++) {
        // ��û�д����*pointer�ַ�
        if(chars[(*(input + i))] == 0) {
            *output = *(input + i);
            chars[(*(input + i))]++;
            output++;
        }
    }

    *output = '\0';

    return 0;
}

