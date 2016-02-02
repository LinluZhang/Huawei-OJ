#include <stdlib.h>
#include "oj.h"
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

char value[1000][9];
unsigned int len = 0;


/*****************************************************************
����:�洢������ַ���

����:�ַ���

���:��

����:0��ʾ�ɹ�,��������-1
****************************************************************/
int  AddString(char *strValue) {

    if(strValue == NULL) {
        return -1;
    }

    int cnt = 0;
    // ���ַ����ĳ���
    while(strValue[cnt] != '\0') {
        cnt++;
    }

    // ԭ�����е�λ��
    int idx = 0;

    while(idx + 8 <= cnt) {
        for(int i = 0; i < 8; i++) {
            value[len][i] = strValue[idx + i];
        }

        value[len][8] = '\0';

        len++;
        idx += 8;
    }


    // ˵����������µ�
    if(idx < cnt || cnt == 0) {
        int num = (cnt - idx);
        for(int i = 0; i < num; i++) {
            value[len][i] = strValue[idx + i];
        }

        for(int i = num; i < 8; i++) {
            value[len][i] = '0';
        }

        value[len][8] = '\0';

        len++;
    }



    return 0;
}

/****************************************************************
����:��ȡ��λ��Ķ�ά����ĳ���

����:��

���:��

����:��ά���鳤��
******************************************************************/
int  GetLength() {
    return len;
}

/*****************************************************************************
����:����λ��Ķ�ά���飬������Ķ�ά�������Ƚ�

����:strInput:�����ά����,iLen������Ķ�ά����ĳ���

���:��

����:�����,����0;�����,����-1.����:-1;
******************************************************************************/
int  ArrCmp(char strInput[][9],int iLen) {

    if(strInput == NULL || iLen < 1 || iLen != len) {
        return -1;
    }

    for(int i = 0; i < iLen; i++){
        for(int j = 0; j < 9; j++) {
            if(value[i][j] != strInput[i][j]) {
                return -1;
            }
        }
    }
    return 0;
}

void printMatrix() {
    for(int i = 0; i < len; i++) {
        cout << "|" << value[i] << "|" << endl;
    }
}

