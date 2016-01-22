#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "oj.h"

// ���ܣ�����һ��m��n�� ��С������
// ���룺 int * pArray ָ�������һ��Ԫ�ص�ָ��,mΪ������ nΪ���� ���밴��i������
// ���������i��������ɺ������ŵ����ָ���ĵ�ַ��	(i��ȡֵ��Χ 1 - n)
// ���أ�

// ������i�к͵�j�е�����
void ExchangeRow(int * arr, unsigned int iRow, unsigned int jRow, unsigned int colNum) {

    int t;
    int iEnd = (iRow + 1)*colNum;

    for(int i = iRow*colNum, j = jRow*colNum; i < iEnd; i++, j++) {
        t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}

int NeedChange(int * arr, int iRow, int iCol, int jRow, int jCol, int colNum) {
    int i= iRow*colNum  + iCol;
    int iEnd = (iRow + 1)*colNum;
    int j = jRow*colNum + jCol;

    while(i < iEnd) {
        if(arr[i] != arr[j]) {
            return arr[i] - arr[j];
        } else {
            i++;
            j++;
        }
    }

    return 0;
}

void RangeArray(int * pArray,unsigned int  m, unsigned int  n,unsigned int  i) {
    if(pArray == NULL || m < 1 || n < 1 || i < 1 || i > n) {
        return;
    }

    i--;
    for(int row = 0; row < m; row++) {
        for(int nxt = row + 1; nxt < m; nxt++) {
            int rst = NeedChange(pArray, row, i, nxt, i, n);
            // ˵��Ҫ����
            if(rst > 0) {
                ExchangeRow(pArray, row, nxt, n);
            }
        }
    }
}



