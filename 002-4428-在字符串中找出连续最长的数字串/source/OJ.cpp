#include <stdlib.h>
#include "oj.h"


/*
���ܣ����ַ������ҳ�����������ִ�������������ĳ��ȷ���
����ԭ�ͣ�
    unsigned int Continumax(char** pOutputstr,  char* intputstr)
���������
    char* intputstr  �����ַ���
���������
    char** pOutputstr: ����������ִ����������������ִ��ĳ���Ϊ0��Ӧ�÷��ؿ��ַ���
    pOutputstr ָ����ڴ�Ӧ���ں�������malloc�������룬�ɵ��ô������ͷ�
����ֵ��
  ����������ִ��ĳ���
 */
unsigned int Continumax(char** pOutputstr,  char* intputstr) {

    if(intputstr == NULL) {
        *pOutputstr = (char *) malloc(sizeof(char));
        (*pOutputstr)[0] ='\0';
        return 0;
    }

    // ����������ִ�����ʼλ��
    int maxIdx = 0;
    // ����������ִ��ĳ���
    int maxLen = 0;

    for(int i = 0, j; intputstr[i] != '\0';) {
        j = i;

        // �ҵ�һ������
        while(intputstr[j] != '\0' && (intputstr[j] < '0' || intputstr[j] > '9')) {
            j++;
        }

        // ���������ֺ�ĵ�һ��������
        i = j;
        while(intputstr[i] != '\0' && (intputstr[i] >= '0' && intputstr[i] <= '9')) {
            i++;
        }

        if(i - j > maxLen) {
            maxIdx = j;
            maxLen = i - j;
        }
    }

    // �ַ�����������
    if(maxLen > 0) {
        (*pOutputstr) = (char *) malloc((maxLen + 1)*sizeof(char));

        for(int i = 0; i < maxLen; i++) {
            (*pOutputstr)[i] = intputstr[maxIdx];
            maxIdx++;
        }

        (*pOutputstr)[maxIdx] = '\0';
        return maxLen;
    }
    // �ַ����в�������
    else {
        *pOutputstr = (char *) malloc(sizeof(char));
        (*pOutputstr)[0] ='\0';
        return 0;
    }
}

