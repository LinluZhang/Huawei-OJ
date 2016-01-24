/******************************************************************************

Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

******************************************************************************
File Name     :
Version       :
Author        :
Created       :
Last Modified :
Description   :
Function List :

History       :
1.Date        :
Author      :
Modification: Created file

******************************************************************************/
#include <algorithm>
#include <vector>
using namespace std;

//����һ���Ǹ��������ҵ�����Ǹ������а��������ݼ�����һ�����ֵĵݼ�����ָ���ڵ���λ�Ӵ�С���е����֡�
//�磺 95345323���ݼ����У�953,95,53,53,532,32, ��ô���ĵݼ���Ϊ953��
//������������Ϊ����������-1��
int getMaxDegressiveNum (int num) {
    if(num < 0 ){
        return -1;
    }

    int cnt = 0;
    int t = num;

    // ������ÿһλ
    vector<int> intVector;

    do {
        intVector.push_back(t%10);
        t /= 10;

    } while(t != 0);

    // ��תvector
    reverse(intVector.begin(), intVector.end());

    int temp;
    int i;
    int max;

    max = temp = intVector[0];
    for(i=1; i< intVector.size(); i++)
    {
        if (intVector[i] < intVector[i-1]) {
            temp = temp * 10 + (intVector[i]);
        }

        else {
            temp = intVector[i];
        }

        if (temp > max) {
            max = temp;
        }

    }
    return max;

}

///////////////////////////////////////////////////////// ���淽��ʾ��ͨ�����в�������
/*
int getNum(vector<int> &intVector, int beg, int end) {
    int rst = 0;
    while(beg < end) {
        rst = rst * 10 + intVector[beg];
        beg++;
    }

    return rst;
}


int getMaxDegressiveNum2 (int num) {

    if(num < 0 ){
        return -1;
    }

    int cnt = 0;
    int t = num;

    // ������ÿһλ
    vector<int> intVector;

    do {
        intVector.push_back(t%10);
        t /= 10;

    } while(t != 0);

    // ��תvector
    reverse(intVector.begin(), intVector.end());

    int rst = -1;
    int prev = 0;
    int next = 1;
    while(next < intVector.size()) {
        while(next < intVector.size() && intVector[next - 1] > intVector[next]) {
            next++;
        }

        int v = getNum(intVector, prev, next);
        if(rst < v) {
            rst = v;
        }
        prev = next;
        next++;

    }

    if(next == 1) {
        rst = num;
    }


    return rst;
}

*/
