/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     :
  Version       :
  Author        :
  Created       : 2012/07/18
  Last Modified :
  Description   :
  Function List :

  History       :
  1.Date        : 2012/07/18
    Author      :
    Modification: Created file

******************************************************************************/


/************************************************************************/
/*  GetExtFibonacci                                                         */
/*  ������չFibonacci���е�ǰ2������first��second��Ҫ�õ������ֵ����к�num  */
/*  ���룺��չFibonacci���ж�Ӧ����ŵ�����                                 */
/************************************************************************/
int GetExtFibonacci(int first , int second, int num) {
    if(num < 1) {
        return 0;
    }

    if(num == 1) {
        return first;
    } else if (num == 2) {
        return second;
    }

    int rst = 0;

    for(int i = 3; i <= num; i++) {
        rst = first + second;
        first = second;
        second = rst;
    }


    return rst;
}

/************************************************************************/
/*  CalcTotalValueOfExtFibonacci                                        */
/*  ������չFibonacci���е�ǰ2������first��second�������ֵ����к�num    */
/*  �������չFibonacci���ж�Ӧ����ŵ�����֮ǰ������������б��������е�����֮��         */
/************************************************************************/
int CalcTotalValueOfExtFibonacci(int first , int second, int num) {

    if(num <1) {
        return 0;
    }

    if(num == 1) {
        return first;
    }

    if(num == 2) {
        return first + second;
    }

    int rst = GetExtFibonacci(first, second, num) + CalcTotalValueOfExtFibonacci(first, second, num - 1);


    return rst;
}

