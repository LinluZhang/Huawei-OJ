#include <stdlib.h>
#include "oj.h"
#include <vector>
#include <string>

using namespace std;

// ��ȡ�����ĸ�λ �Լ� ��������
vector<int> AllNum(int num,int &reverseNum) {
    vector<int> result;
    if(num == 0) {
        result.push_back(0);
        return result;
    }
    reverseNum = 0;
    int tmp = num;
    int c;
    while(tmp) {
        c = tmp % 10;
        result.push_back(c);
        reverseNum = reverseNum * 10 + c;
        tmp /= 10;
    }
    return result;
}

/*
����:
	����һ��������5λ��������
	Ҫ��:
		1��������Ǽ�λ��
		2���ֱ����ÿһλ����
		3�������������λ���֣�����ԭ��Ϊ321,Ӧ���123
����:
	���� iInput,λ��������5������

���:
    ����λ��		iNum
	�ո���������    strRst
	��������		iOutput

����:
	0  �ɹ�
	-1 ������Ч
*/

int ProcessX(int iInput, int& iNum, char * strRst, int& iOutput){
    // ��������
    if(strRst == NULL){
        return -1;
    }


    // ����
    bool positive = true;
    // ����Ƿ�Ϊ���������ҰѸ����������
    if(iInput < 0){
        positive = false;
        iInput = -iInput;
    }

    // �������ϵĸ�λ��������������ķ�ת��
    vector<int> vec = AllNum(iInput,iOutput);

    // ������Ǽ�λ��
    iNum = vec.size();

    // �������
    int index = 0;
    if(!positive){
        iOutput = -iOutput;
        strRst[index++] = '-';
    }

    // ����ʽ�ֱ����ÿһλ����
    for(int i = iNum - 1;i >= 0;--i){
        if(i == iNum - 1){
            strRst[index++] = vec[i] + '0';
        }
        else{
            strRst[index++] = ' ';
            strRst[index++] = vec[i] + '0';
        }
    }
    strRst[index] = '\0';

    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////

// ����ķ���ĩ��ͨ��ȫ����������
// �����ڲ��Թ�����ʹ�õ����������ķ���һ�£���֪��δͨ���Ĳ���������������ʲô
int ProcessX2(int iInput, int& iNum, char * strRst, int& iOutput) {

    if(strRst == NULL) {
        return -1;
    }

    iNum = 0;
    iOutput = 0;
    int isNagetive = 0;
    if(iInput < 0) {
        isNagetive = 1;
        // �������
        iInput *= -1;
    }

    do {
        int v = iInput % 10;
        iInput /= 10;

        strRst[2*iNum + isNagetive] = (char)('0' + v);
        strRst[2*iNum + isNagetive + 1] = ' ';
        iOutput = 10*iOutput + v;
        iNum++;

    } while(iInput != 0);

    strRst[2*iNum + isNagetive - 1] = '\0';

    if(isNagetive == 1) {
        strRst[0] = '-';
        iOutput *= -1;
    }

    return 0;
}
