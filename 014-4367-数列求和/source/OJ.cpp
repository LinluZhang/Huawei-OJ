#include <iostream>
#include "OJ.h"


/*
void GetResult(int InputNum, double *NumResult);
���������
		Int  InputNum������һ�������������б��ʽ����
	 	char *NumResult��������ʽ��ֵ
����ֵ��
		void

*/

void GetResult(int InputNum, double *NumResult) {

    double rst = 0;
    double part = 1;
    for(int i = 1; i <= InputNum; i++) {
        part *= fact(i);
        rst += part;
        //std::cout << part << " " << rst << std::endl;
    }

    *NumResult = rst;
    //std::cout << (*NumResult) << std::endl;
    return ;
}

double fact(int k) {
    return 1.0 / k;
}

