#include <cstdlib>
#include "OJ.h"

/*
����:��������������飬�������Ԫ���е����ֵ�����ֵ�ĸ�������Сֵ����Сֵ�ĸ���

����:int * pInputInteger����������ָ��
	 int * InputNum������Ԫ�ظ���

���:int * pMaxValue�����������ֵ
  	 int * pMaxNum�����������ֵ�ĸ���
	 int * pMinValue����������Сֵ
     int * pMinNum����������Сֵ�ĸ���

����:void
*/

void OutputMaxAndMin(int * pInputInteger, int InputNum, int * pMaxValue, int * pMaxNum, int * pMinValue, int * pMinNum) {

    if(InputNum < 1 || pInputInteger == NULL || pMaxValue == NULL
            || pMinValue == NULL || pMinNum == NULL) {
        return ;
    }

    *pMaxValue = pInputInteger[0];
    *pMaxNum = 1;

    *pMinValue = pInputInteger[0];
    *pMinNum = 1;

    for(int i = 1; i < InputNum; i++) {

        // cout << pInputInteger[i] << " " << *pMaxValue << " " << *pMinValue << endl;

        if(pInputInteger[i] < *pMinValue) {

            *pMinValue = pInputInteger[i];
            *pMinNum = 1;
        } else if(pInputInteger[i] == *pMinValue) {
            (*pMinNum)++;
        }

        if(pInputInteger[i] > *pMaxValue) {
            *pMaxValue = pInputInteger[i];
            *pMaxNum = 1;
        } else if(pInputInteger[i] == *pMaxValue) {
            (*pMaxNum)++;
        }
    }
    return;
}

