#include <stdlib.h>
#include "OJ.h"

/*
����: �ҳ��ַ����е�һ�����ִ��������ַ�

����: char* pInputString���ַ���

���: char* pChar�����ִ��������ַ�

����: false �쳣ʧ��
	  true  ����ɹ�
*/
bool FindChar(char* pInputString, char* pChar) {

    if(pInputString == NULL || pInputString[0] == '\0') {
        return false;
    }

    int arr[256][2] = {0};

    for(int i = 0; i < 256; i++) {
        arr[i][0] = arr[i][1] = 0;
    }

    for(int i = 0; pInputString[i] != '\0'; i++) {
        // ��¼�ַ����ֵĴ���
        arr[pInputString[i]][0]++;
        if(arr[pInputString[i]][1] == 0) {
            // ��¼�ַ���һ�γ��ֵ�λ��
            arr[pInputString[i]][1] = i;
        }
    }

    int cnt = 0;
    int idx = 0;

    for(int i = 0; i < 256; i++) {
        // ��¼�ַ��������Ĵ����͵�һ�γ��ֵ�λ��
        if(cnt < arr[i][0]) {
            idx = i;
            cnt = arr[i][0];
        } else if(cnt == arr[i][0]) {
            if(idx > i) {
                idx = i;
            }
        }
    }

    //cout << pInputString << endl;
    //cout << idx << endl;
    //cout << (char)(idx) << endl;



    *pChar = (char)(idx);


    return true;
}

