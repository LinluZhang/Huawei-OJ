#include <iostream>
#include<stdlib.h>
#include<set>
#include<vector>

#include "OJ.h"

using namespace std;

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

    if(input == NULL || output == NULL) {
        return -1;
    }

    set<char> charSet;
    vector<char> charVector;

    for(int i = 0; input[i] != '\0'; i++) {
        if(charSet.find(input[i]) == charSet.end()) {
            charSet.insert(input[i]);
            charVector.push_back(input[i]);
        }
    }

    int idx = 0;
    for(vector<char>::iterator it  = charVector.begin(); it != charVector.end(); it++) {
        output[idx] = *(it);
        idx++;
    }

    output[idx] = '\0';


    return 0;
}
