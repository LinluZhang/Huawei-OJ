#include "IPAddressValid.h"
#include <cstring>
#include <cstdio>

using namespace std;

bool isIPAddressValid(const char* pszIPAddr) {

    if(NULL == pszIPAddr) {
        return false;
    }

    // �ַ����ĳ���
    int lenIPAddr=strlen(pszIPAddr);
    int startIndex;
    int endIndex;

    //ȥ��ǰ��ո�
    for(startIndex = 0; startIndex < lenIPAddr; startIndex++) {
        if(pszIPAddr[startIndex] != ' ') {
            break;
        }
    }

    for(endIndex = lenIPAddr - 1; endIndex >= 0; endIndex--) {
        if(pszIPAddr[endIndex]!=' ') {
            break;
        }
    }

    // ���ǿո�����
    if(endIndex <= startIndex) {
        return false;
    }

    char inputStr[200];
    // IP�ַ�����ȥ����β�ո��ĳ���
    int lenInputStr = endIndex - startIndex + 1;

    // �����ݿ�����inputStr��
    strncpy(inputStr, &pszIPAddr[startIndex], lenInputStr);

    // ���ý���λ��
    inputStr[lenInputStr] = '\0';
    // ���ҵ�ĺϷ���
    // .�ŵĸ���
    int countDot = 0;

    for(int i = 0; i < lenInputStr; i++) {
        if(inputStr[i] == '.') {
            // �������һ
            countDot ++;

            // ��һ���������һ���ǵ��
            if(i == 0 || i == lenInputStr - 1) {
                return false;
            }

            // ���ǰһ������������
            if(inputStr[i - 1] < '0' || inputStr[i-1] > '9') {
                return false;
            }

            // ��ź�һ������������
            if(inputStr[i + 1] < '0'|| inputStr[i + 1] > '9') {
                return false;
            }

        }
    }

    // ��Ų�������
    if(countDot != 3) {
        return false;
    }
    char *pCut;
    // ���ַ�����.�Ž��зָ�
    // �õ���һ�����ֵ��׵�ַ
    pCut = strtok(inputStr, ".");

    while(NULL != pCut) {
        int num;
        // ��һ���ַ����ж�����ָ����ʽ��������ݡ�
        // ���ַ���ת������
        sscanf(pCut, "%d", &num);
        // ֵ��Ϊ0��������ǰ��0
        if(num != 0 && pCut[0] == '0') {
            return false;
        }

        // ֵ����255
        if(num > 255) {
            return false;
        }

        // �״ε���ʱ��sָ��Ҫ�ֽ���ַ�����֮���ٴε���Ҫ��s���NULL��
        // �õ��ڶ����ֵ��׵�ַ
        pCut = strtok(NULL,".");
    }

    return true;
}
/*
// ��������Ӳ���ͨ��ȫ��������������֪��δͨ����������ʲô

bool ipToInt(const char * b, const char * e, int &rst) {

    //cout << *b << " " << *e << endl;

    // IP��ַ������ǰ��0�����ߵ�һ���ַ��������������ַ�
    if(*b < '0' || *b > '9') { //
        return false;
    }


    int len = e - b + 1;
    int idx = 0;
    rst = 0;

    // cout << idx << "-" << len << endl;
    while( idx < len) {
        if(b[idx] >= '0' && b[idx] <= '9') {
            rst = rst * 10 + (b[idx] - '0');
        } else {
            return false;
        }

        idx++;
    }

    // ��Ϊ0������ǰ��0
    if(rst > 0 && *b == '0') {
        return false;
    }

    if(rst >= 0 && rst < 256) {
        return true;
    }

    return false;


}

// ע��00.0.00.00�ǺϷ���
bool isIPAddressValid2(const char * pszIPAddr) {

    if(pszIPAddr == NULL || pszIPAddr[0] == '\0') {
        return false;
    }


    int b = 0;
    int e;

    // ����ߵ�һ���ǿհ��ַ�
    while(pszIPAddr[b] != '\0' && pszIPAddr[b] == ' ') {
        b++;
    }

    e = b + 1;
    while(pszIPAddr[e] != '\0') {
        e++;
    }
    e--;

    // ���ұߵ�һ���ǿհ��ַ�
    while(b <=e && pszIPAddr[e] == ' ') {
        e--;
    }

    int idx = 0;
    int cnt = 0;
    while( idx <= e) {
        while(idx <= e && pszIPAddr[idx] != '.') {
            idx++;
        }

        // ע�⵱������������..����b=idx�����
        if(b == idx) {
            return false;
        }

        int v;
        bool result = ipToInt(pszIPAddr + b, pszIPAddr + idx - 1, v);
        cnt++;

        if(!result) {
            return false;
        }

        b = idx + 1;
        idx = idx + 1;
    }

    return cnt == 4;
    //return true;
}

*/
