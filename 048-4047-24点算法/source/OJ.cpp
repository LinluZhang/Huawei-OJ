/******************************************************************************

  Copyright (C), 2001-2013, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     :
  Version       :
  Author        :
  Created       : 2013/03/12
  Last Modified :
  Description   :
  Function List :

  History       :
  1.Date        : 2013/03/12
    Author      :
    Modification: Created file

******************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <list>
#include <iostream>

#include "OJ.h"

using namespace std;

// �����沨��ʽ��ֵ
void calInversePoland(list<float> &intList, bool &rst) {

/*
     for (list<float>::iterator itr = intList.begin(); itr != intList.end(); itr++) {
         int i = *itr;
        if(i >= 0 && i <= 10) {
            cout << i << " ";
         } else {
            cout << (char)i << " ";
         }
     }

     cout << endl;
*/
    list<float> mstack;;

    for (list<float>::iterator itr = intList.begin(); itr != intList.end(); itr++) {

        // ���������
        if (*itr >= 0 && *itr <= 10) {
            mstack.push_back(*itr);
        } else {
            float a = mstack.back();
            mstack.pop_back();
            float b = mstack.back();
            mstack.pop_back();
            float c = 0;
            switch ((char)(*itr)) {
            case '+':
                c = a + b;
                break;
            case '-':
                c = a - b;
                break;
            case '*':
                c = a * b;
                break;
            case '/':
                // ��������Ϊ0
                if (b == 0) {
                    return;
                }
                c = a / b;
                break;
            }

            mstack.push_back(c);
        }

    }

    float v = mstack.back();
    //cout << v << endl;
    rst = (v == 24);
}

void to24(float *arr, bool *used, int len, int numCnt, int optCnt,
                         list<float> &intList, bool &rst) {


    // ����Ѿ��ҵ��𰸾Ͳ����в�����
    if (rst) {
        return;
    }
    // �Ѿ�������沨��ʽ�Ĺ���
    if (numCnt > optCnt && numCnt + optCnt == 7) {
        calInversePoland(intList, rst);
    }
    // ��Ҫ�����沨��ʽ
    else if (numCnt > optCnt) {

        for (int i = 0; i < len; i++) {
            // ���arr[i]��û�б�ʹ�ù�������arr[i]�������
            if (!used[i] || arr[i] < 0 || arr[i] > 10) {
                // ���������
                if (arr[i] >= 0 && arr[i] <= 10) {
                    intList.push_back(arr[i]);
                    numCnt++;
                    used[i] = true;


                    to24(arr, used, len, numCnt, optCnt, intList, rst);

                    // �ҵ���һ���𰸾ͷ���
                    if (rst) {
                        return;
                    }

                    intList.pop_back();
                    numCnt--;
                    used[i] = false;

                }
                // ����ǲ������������arr[i]֮ǰ������������Ȳ�����������
                else if (numCnt + 1 > optCnt) {
                    intList.push_back(arr[i]);
                    optCnt++;
                    used[i] = true;


                    to24(arr, used,len, numCnt, optCnt, intList, rst);

                    // �ҵ���һ���𰸾ͷ���
                    if (rst) {
                        return;
                    }

                    intList.pop_back();
                    optCnt--;
                    used[i] = false;
                }
            }
        }
    }
}

// a, b, c, d����[1, 10]��
bool Game24Points(int a, int b, int c, int d){
    float arr[8] = {a, b, c, d, '+', '-', '*', '/'};
    bool used[8] = {false};
    list<float> intList;

    bool rst = false;

    // ������ϵ��沨�����ʽ
    for (int i = 0; i < 4; i++) {
        used[i] = true;



        intList.push_back(arr[i]);

        to24(arr, used, 8, 1, 0, intList, rst);

        if (rst) {
            return true;
        }

        // �ֳ���ԭ
        intList.pop_back();
        used[i] = false;
    }


    return false;
}

