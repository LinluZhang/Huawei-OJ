/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     :
  Version       :
  Author        :
  Created       : 2013/08/10
  Last Modified :
  Description   :
  Function List :

  History       :
  1.Date        : 2013/08/10
    Author      :
    Modification: Created file

******************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <vector>


using namespace std;
/*
��ϸ������
int JudgeTrainSequence (int maxNum, char *pOutSeq);
���������
	 	int maxNum����վ�Ļ������
	 	char* pOutSeq��ʹ���ַ�����ʾ�𳵳�վ����
���������ָ��ָ����ڴ�����֤��Ч����
	 	�ޡ�
����ֵ��
		Int: ��������Ľ�վ�����жϣ��������ĳ�ս�����ǿ��ܵģ�����1�����򷵻�0��

*/

int JudgeTrainSequence (int maxNum, char *pOutSeq) {

    if(maxNum < 1 || pOutSeq == NULL) {
        return 0;
    }

    vector<char> push;
    vector<char> pop;

    for(int i = 0; i < maxNum; i++) {
        push.push_back((char)('1' + i));
    }

    for(int i = 0; i < maxNum; i++) {
        pop.push_back(pOutSeq[i]);
    }

    vector<char> mstack;
    // ���ڼ�¼��ջ����Ԫ�صĴ���λ��
    int pushIndex = 0;
    // ���ڼ�¼��ջ����Ԫ�صĴ���λ��
    int popIndex = 0;

    // ������г�ջԪ��Ҫ����
    while(popIndex < pop.size()) {
        // ��ջԪ�ػ�δȫ����ջ�������£����ջΪ�գ�����ջ����Ԫ�ز��뵱ǰ�������ȣ�
        // ��һֱ����ջ������
        // ֱ����ջԪ��ȫ����ջ�����ҵ���һ���뵱��ջԪ����ȵ�Ԫ��
        while(pushIndex < push.size() &&
                (mstack.empty() || mstack[mstack.size()-1] != pop[popIndex])) {
            mstack.push_back(push[pushIndex]);
            pushIndex++;
        }

        // �������һ������ջ�������ҵ������ջ��Ԫ����ȵ�Ԫ��
        if (mstack[mstack.size() - 1] == pop[popIndex]) {
            // ��Ԫ�س�ջ
            mstack.pop_back();
            // ������һ����ջԪ��
            popIndex++;
        }
        // ���û���ҵ����ջԪ����ȵ�Ԫ�أ�˵�������ջ˳���ǲ��Ϸ���
        // �ͷ���false
        else {
            return 0;
        }
    }

    return 1;
}


