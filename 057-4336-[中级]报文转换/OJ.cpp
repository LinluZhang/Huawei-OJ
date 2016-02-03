#include <stdlib.h>
#include "oj.h"

/*
����:
    �������ı��İ�����ת������һ�����ĺ������
    ת���������£�
    �������������0x7E��ת���Ϊ2���ֽ�0x7D 0x5E���������0x7D��ת���Ϊ2���ֽ�0x7D 0x5D������ڱ���ͷβ������һ��0x7E���硣

    ʾ����ÿ���ֽ���ʮ����������ʾ��
    ����ԭʼ���ģ�1D 2B 3C 4D 5E 7E 6F 7D 7E
    ת����ı��ģ�7E 1D 2B 3C 4D 5E 7D 5E 6F 7D 5D 7D 5E 7E

����:
char* pInput: ���������뱨�ģ��ڴ�ռ��ɵ�����������ͷ�
int iLen: �������ĵĳ���
���:
char* pOutput��ת����ı��ģ��ڴ�ռ��ɵ�����������ͷ�
����:
int�� �ɹ� 0�� ʧ�� -1

*/

int PktTrans(char* pInput, int iLen, char* pOutput) {

    if(pInput == NULL || pOutput == NULL || iLen < 1) {
        return -1;
    }

    int idx = 0;
    pOutput[idx++] = 0x7E;

    for(int i = 0; i < iLen; i++) {

        if(pInput[i] == 0x7E) {
            pOutput[idx++] = 0x7D;
            pOutput[idx++] = 0x5E;
        } else if(pInput[i] == 0x7D) {
            pOutput[idx++] = 0x7D;
            pOutput[idx++] = 0x5D;
        } else {
            pOutput[idx++] = pInput[i];
        }
    }

    pOutput[idx] = 0x7E;
    return 0;
}
