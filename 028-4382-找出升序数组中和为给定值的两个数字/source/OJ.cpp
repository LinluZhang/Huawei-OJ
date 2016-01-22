#include <stdio.h>
#include "OJ.h"

/*
����: ����һ���Ѿ�������������������һ�����֣��������в�����������ʹ�����ǵĺ�������������Ǹ����֡�����ж�����ֵĺ͵�����������֣��������һ�Լ��ɡ�

����: int aData[]           // ��������
      unsigned int uiLength // ����Ԫ�ظ���
      int sum,              // ������������ĺ�

���: int *pNum1            // ��һ�����֣���Ӧ��������С��
      int *pNum2            // �ڶ������֣���Ӧ�����������

����: �ҵ�����true���쳣����false
*/
bool FindTwoNumbersWithSum(int aData[], unsigned int uiLength, int sum, int *pNum1, int *pNum2) {
    if(aData == NULL) {
        return false;
    }

    for(int i = 0, j = uiLength -1; i < j; ) {
        if(aData[i] + aData[j] == sum) {
            *pNum1 = aData[i];
            *pNum2 = aData[j];
            return true;
        } else if(aData[i] + aData[j] < sum) {
            i++;
        } else {
            j--;
        }
    }


    return false;
}
