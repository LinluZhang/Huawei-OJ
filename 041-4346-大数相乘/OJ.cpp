#include <vector>
#include <string>

#include "oj.h"

using namespace std;

// ���ַ����Ӹ�λ�����ͷ�ת
void numReverse(const std::string s, vector<int> &vt) {

    int len = s.size();
    for(int i = len - 1; i >= 0; i--) {
        vt.push_back(s[i] - '0');
    }
}
/*****************************************************************************
 Prototype    : multiply
 Description  : �������ⳤ�ȵĳ��������, ������
 Input Param  :
                const std::string strMultiplierA  ����A
                const std::string strMultiplierB  ����B
 Output       :
                std::string strRst            �˷����
 Return Value :
                int                       0  ��ȷ
                                         -1  �쳣
*****************************************************************************/
int multiply (const std::string strMultiplierA,const std::string strMultiplierB, std::string &strRst) {

    if(&strMultiplierA == NULL || strMultiplierA.empty()
       || &strMultiplierB == NULL || strMultiplierB.empty() || &strRst == NULL) {
        return -1;
    }
/*
    int aNegative = 0;
    int bNegative = 0;
    if(strMultiplierA[0] == '-' ) {
        strMultiplierA = strMultiplierA.substr(1, strMultiplierA.size() - 1);

    }
*/

    vector<int> a;
    vector<int> b;
    numReverse(strMultiplierA, a);

    numReverse(strMultiplierB, b);

    vector<int> rst;
    rst.assign(a.size() + b.size() +  1, 0);

    for(int i = 0; i < a.size(); i++)  {
        int carry = 0;
        for(int j = 0; j < b.size(); j++) {

            int sum = a[i] * b[j] + rst[i + j] + carry;

            // ��һλ�Ľ�λ
            carry = sum / 10;
            // ��ǰλ�ĺ�
            rst[i + j] = sum % 10;
        }

        int idx = b.size() + i;
        while(carry > 0) {
            carry = carry + rst[idx];
            rst[idx] = carry % 10;
            carry /= 10;
            idx++;
        }
    }

    int idx = 0;
    int findHigest = 0;
    for(vector<int>::reverse_iterator itr = rst.rbegin(); itr != rst.rend(); itr++) {

        if(*itr == 0 && findHigest == 0) {
            continue;
        }
        findHigest = 1;
        strRst  += *itr + '0';
        idx++;
    }

    // ����ȫ������0
    if(findHigest == 0) {
        strRst += '0';
    }

    return 0;
}
