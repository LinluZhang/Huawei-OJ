/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     :
  Version       :
  Author        :
  Created       : 2009/10/10
  Last Modified :
  Description   :
  Function List :

  History       :
  1.Date        : 2009/10/10
    Author      :
    Modification: Created file

******************************************************************************/
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string trim(string s);
string format(string s);
string appendZero(string s, int n);
void strToArr(string s, vector<int> &v);
bool mcompares(vector<int> &m, vector<int> &s);
void minusOper(vector<int> &m, vector<int> &s, vector<int> &rst);
void addOper(vector<int> &m, vector<int> &s, vector<int> &rst);
void printVector(vector<int> &v);
/*****************************************************************************
Description  : �������ⳤ�ȵ��������
Prototype    : int Decrease(const char *pMinuend, const char *pSubtrahend, char **ppResult)
Input Param  : const char *pMinuend     ����������\0��ʾ�ַ�������
               const char *pSubtrahend  ��������\0��ʾ�ַ�������
Output       : char **ppResult          ���������������\0��ʾ�ַ�������
Return Value : �ɹ�����0   ʧ�ܷ���-1
*****************************************************************************/
int Decrease(const char *pMinuend, const char *pSubtrahend, char **ppResult) {

    if(pMinuend == NULL || pMinuend[0] == '\0' || pSubtrahend == NULL
            || pSubtrahend[0] == '\0' || ppResult == NULL) {
        return -1;
    }

    string mstr(pMinuend);
    string sstr(pSubtrahend);



    // ȥ�����˿ո�
    mstr = trim(mstr);
    sstr = trim(sstr);

    // ��¼���������Ǹ���
    bool mPositive = true;
    bool sPositive = true;

    // ȥ������
    if(mstr[0] == '+') {
        mstr = mstr.substr(1, mstr.length() - 1);
    } else if(mstr[0] == '-') {
        mPositive = false;
        mstr = mstr.substr(1, mstr.length() - 1);
    }

    if(sstr[0] == '+') {
        sstr = sstr.substr(1, sstr.length() - 1);
    } else if(sstr[0] == '-') {
        sPositive = false;
        sstr = sstr.substr(1, sstr.length() - 1);
    }



    // ���������ַ���
    mstr = format(mstr);
    sstr = format(sstr);



    // ��¼�ж���λС��
    int mDecimal = mstr.find('.');
    int sDecimal = sstr.find('.');


    if (mDecimal == -1) {
        mDecimal = 0;
    } else {
        mDecimal = mstr.length() - (mDecimal + 1);
    }

    if (sDecimal == -1) {
        sDecimal = 0;
    } else {
        sDecimal = sstr.length() - (sDecimal + 1);
    }

    // ��������С��λ��
    if (mDecimal > sDecimal) {
        // �ڼ������������
        sstr = appendZero(sstr, mDecimal - sDecimal);
    }
    // ������λ����С�ڱ�����
    else {
        // �ڱ������������0
        mstr = appendZero(mstr, sDecimal - mDecimal);
    }

    // ��¼�����С��λ��
    int decimal = mDecimal > sDecimal ? mDecimal : sDecimal;
    vector<int> m;
    vector<int> s;
    strToArr(mstr, m);
    strToArr(sstr, s);

    /////////////////////////////////////////////////////////
   // printVector(m);
   // printVector(s);
    /////////////////////////////////////////////////////////


    // �������Ƿ���ڵ���s
    bool isMgeS = mcompares(m, s);

    //cout << "m >= s ? " << isMgeS << endl;

    vector<int> rst;
    bool isResultPositive = true;

    // �жϽ���������Ǹ���
    // �������������������ҵ�һ������С�ڵڶ�����
    if (mPositive && sPositive && isMgeS) {
        isResultPositive = true;
        minusOper(m, s, rst);
    }
    // �������������������ҵ�һ����С�ڵڶ�����
    else if (mPositive && sPositive && !isMgeS) {
        // cout << "====" << endl;
        isResultPositive = false;
        minusOper(s, m, rst);
    }
    // ��һ�������������ڶ������Ǹ���
    else if (mPositive && !sPositive) {
        isResultPositive = true;
        addOper(m, s, rst);
    }
    // ��һ�����Ǹ������ڶ�����������
    else if (!mPositive && sPositive) {
        isResultPositive = false;
        addOper(m, s, rst);
    }
    // ���������Ƿ����������ҵ�һ�������ڵڶ�����
    else if (!mPositive && !sPositive && isMgeS) {
        isResultPositive = false;
        minusOper(m, s, rst);
    }
    // ���������Ƿ����������ҵ�һ����С�ڵڶ�����
    else if (!mPositive && !sPositive && !isMgeS) {
        isResultPositive = true;
        minusOper(s, m, rst);
    }

    /////////////////////////////////////////////////////////
    //printVector(rst);
    /////////////////////////////////////////////////////////

    vector<char> result;

    // �����������
    for (int i = rst.size() - 1; i >= decimal ; i--) {
        result.push_back((char)(rst[i] + '0'));
    }



    // ��С��
    if (decimal > 0) {
        result.push_back('.');
        // ���С������
        for (int i = decimal - 1; i >= 0 ; i--) {
            result.push_back((char)(rst[i] + '0'));
        }
    }

    // ��С��
    if (decimal > 0) {
        int idx = result.size() - 1;

        // ȥ����β��0
        while (result[idx] == '0') {
            idx--;
        }

        // ���һ��С���㣬ȥ��С����
        if (result[idx] == '.') {
            idx--;
        }

        result.resize(idx + 1);
    }

    // ȥ������ǰ����
    int idx = 0;
    while (result[idx] == '0') {
        idx++;
    }

    if (result[idx] == '.') {
        idx--;
    }

    string resultString("");

    for(int i = idx; i < result.size(); i++) {
        resultString.append(1, result[i]);
    }

    if (!isResultPositive) {
        resultString = "-" + resultString;
    }


    *ppResult = (char *)malloc(sizeof(char)*(resultString.length() + 1));
    for(int i = 0; i < resultString.length(); i++) {
        (*ppResult)[i] = resultString[i];
    }

    (*ppResult)[resultString.length()] = '\0';

    //cout << resultString << endl;

    return 0;
}

// ȥ��s���˵Ŀո񣬱�֤s���뺬�пո�������ַ�
string trim(string s) {

    int beg = 0;
    while(beg < s.length() && s[beg] == ' ') {
        beg++;
    }

    int end = s.length() - 1;
    while(end >= 0 && s[end] == ' ') {
        end--;
    }

    return s.substr(beg, end - beg + 1);
}

// �����ַ����Ľ��й��������������������ַ�����00.1-->0.1 .1->0.1 0.-->0.0
string format(string s) {

    // ȥ��ǰ��0
    int pos = 0;
    while (pos < s.length() && s[pos] == '0') {
        pos++;
    }
    s = s.substr(pos, s.length() - pos);

    // ���sΪ�վͷ�����
    if (s.empty()) {
        s = "0";
    } else {
        // ������һ���ַ��ǵ�žͲ�����һ����
        if (s[s.length() - 1] == '.') {
            s += "0";
        }

        // �����һ���ǵ�ţ�������ǰҳ�����һ��0
        if (s.empty()) {
            s = "0" + s;
        }
    }

    return s;
}


string appendZero(string s, int n) {
    for (int i = 0; i < n; i++) {
        s += "0";
    }

    return s;
}

// �������ַ���ת����������������Ϊ�ӵ�λ����λ��ȥ��С����
void strToArr(string s, vector<int> &v) {
    for (int i = s.length() - 1; i >= 0; i--) {
        char c = s[i];
        if (c >= '0' && c <= '9') {
            v.push_back(c - '0');
        }
    }

}

// m�Ƿ���ڵ���s��m��s��ͬ�����С����λ������m��s�Ѿ�����������
bool mcompares(vector<int> &m, vector<int> &s) {
    if (m.size() > s.size()) {
        return true;
    } else if (m.size() < s.size()) {
        return false;
    } else {
        for (int i = m.size() - 1; i >= 0; i--) {
            if (m[i] > s[i]) {
                return true;
            } else if (m[i] < s[i]) {
                return false;
            }
        }
    }

    return true;
}

// m-s��ǰ����m���ڵ���s
void minusOper(vector<int> &m, vector<int> &s, vector<int> &rst) {

    int max = m.size();
    int min = s.size();


    // �Ƿ񱻽�λ
    int borrow = 0;
    int i = 0;
    while (i < min) {
        int mBit = m[i] - borrow;
        int sBit = s[i];

        if (mBit >= sBit) {
            rst.push_back(mBit - sBit);
            borrow = 0;
        } else {
            rst.push_back(10 + mBit - sBit);
            borrow = 1;
        }

        i++;
    }

    while (i < max) {
        int mBit = m[i] - borrow;
        if (mBit >= 0) {
            rst.push_back(mBit);
            borrow = 0;
        } else {
            rst.push_back(10 + mBit);
            borrow = 1;
        }
        i++;
    }

    //printVector(m);
    //printVector(s);
    //printVector(rst);
}
// ��m+s��m��s����ͬλ����С��������m��s�Ѿ�����������
void addOper(vector<int> &m, vector<int> &s, vector<int> &rst) {
    if (m.size() < s.size()) {
        addOper(s, m, rst);
        return;
    }

    int max = m.size();
    int min = s.size();
    int i = 0;
    int carry = 0;


    while (i < min) {
        int sum = s[i] + m[i] + carry;
        carry = sum / 10;
        rst.push_back(sum % 10);
        i++;
    }

    while (i < max) {
        int sum = m[i] + carry;
        carry = sum / 10;
        rst.push_back(sum % 10);
        i++;
    }

    if (carry > 0) {
        rst.push_back(carry);
    }
}

void printVector(vector<int> &v) {
    for(vector<int>::iterator itr = v.begin(); itr != v.end(); itr++) {
        cout << (*itr) << " ";
    }

    cout << endl;
}












