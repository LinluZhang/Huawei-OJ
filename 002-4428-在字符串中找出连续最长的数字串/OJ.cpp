#include <cstdlib>
#include <cstring>
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

    char *pTemp =new char[10];
    // void *memset(void *s, int ch, size_t n);
    // �������ͣ���s��ǰn���ֽ� ��typedef unsigned int size_t ���� ch �滻������ s ��
    // memset����������һ���ڴ�������ĳ��������ֵ�����ǶԽϴ�Ľṹ�������������������һ����췽��
    memset(pTemp,'\0',10);
    char temp[10] = {""};

    // strcpy()������Դ����\0��Ϊ�����жϵģ������copy�ȵ�Buffer��Size��
    // ���Ŀ��ռ䲻��������BufferOverflow����
    // strncpy��ԭ��Ϊ��char * strncpy(char *dest, char *src, size_t n);
    // �佫�ַ���src�����n���ַ����Ƶ��ַ�����dest��(��������strcpyһ������NULL��ֹͣ���ƣ�
    // ���ǵȴչ�n���ַ��ſ�ʼ���ƣ�������ָ��dest��ָ�룬���ԣ��û������size����û��bufferoverfolow�ķ���
    // Ŀǰ��strncpy���ַ��������Ƽ����÷�
    // ��_s�汾���Ǵ�VS2005��ʼ�Ƴ��İ�ȫ�汾��
    // ����_s�汾֮���԰�ȫ������Ϊ�����ڽӿ�������һ������numElems������dest�е��ֽ�����
    // ��ֹĿ��ָ��dest�еĿռ䲻�������³���Bug��ͬʱ����ֵ�ĳɷ��ش�����룬������Ϊ��һЩ��ν
    // �ķ��������char*�������ӿڵĶ���ͱ�ԭ����ȫ�ܶࡣ���ǣ�_s�汾�����Ǳ�׼�⣬���ԣ����Ƽ�ʹ��

    // ���ַ���pTemp�е����ݿ�����temp�У�����Ϊ0���ַ�
    strncpy_s(pTemp, 10, temp, 10);

    // ������봮Ϊ�գ���ֱ�ӷ���
    if (NULL == intputstr) {
        *pOutputstr  = pTemp;
        return 0;
    }

    // �����봮�ĳ���
    size_t strLen = strlen(intputstr);
    // ���������󳤶�
    char* pMaxNum = new char[strLen + 1];
    // �������ִ��ͳ���
    size_t numLen = 0;
    // �������ִ�����󳤶�
    size_t maxNumLen = 0;
    // ��ʼ�����λ��
    size_t startNum = 0;

    // ���ַ������д���
    for(size_t i = 0; i < strLen; ++i) {
        // ֮ǰ�Ƿ����֣������Ǵ�������е�һ������
        if (intputstr[i]>='0' && intputstr[i]<='9') {
            // ��¼�������ʼλ��
            startNum = i;
            // ���ڼ�¼�������ִ�����ĳ���
            numLen = 0;
            // �����ε����ִ�
            while(i < strLen && intputstr[i] >= '0' && intputstr[i] <= '9') {
                ++numLen;
                ++i;
            }

            // ����ҵ������ִ���ԭ���ĳ����͸����µ����ִ�
            if (numLen != 0 && maxNumLen <= numLen) {
                memset(pMaxNum, '\0', strLen + 1);
                strncpy_s(pMaxNum, strLen + 1, intputstr + startNum, numLen);
                maxNumLen = numLen;
            }
        }
    }

    if (maxNumLen == 0) {
        delete [] pMaxNum;
        pMaxNum = NULL;
        *pOutputstr = pTemp;
    } else {
        *pOutputstr = pMaxNum;
    }

    return (unsigned int)maxNumLen;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////
// �������д���ԭ��δ֪��
/*
unsigned int Continumax(char** pOutputstr,  char* intputstr) {

    if(pOutputstr == NULL || intputstr == NULL || intputstr[0] == '\0') {
        *pOutputstr = (char *) malloc(sizeof(char));
        (*pOutputstr)[0] ='\0';
        return 0;
    }

    // �ַ�������Ϊ0
    if(intputstr[0] == '\0') {
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
*/
