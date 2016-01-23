
#include "OJ.h"
#include <string.h>
#include <stdio.h>
#include <list>
#include <iostream>
using namespace std;

/*
Description
         ����һ������������ȡ�ö������Ŀ����ȡ�
Prototype
         int GetBiNodeInfo(BiNode &head, unsigned int *pulWidth, unsigned int *pulHeight)
Input Param
         head   ��Ҫ��ȡ��ȵĶ�����ͷ���
Output Param
         pulWidth   ���
         pulHeight  �߶�
Return Value
         0          �ɹ�
         1          ʧ�ܻ������쳣
*/
int GetBiNodeInfo(BiNode &head, unsigned int *pulWidth, unsigned int *pulHeight) {

    if(&head == NULL || pulWidth == NULL || pulHeight == NULL) {
        return 1;
    }

    *pulWidth = 0;
    *pulHeight = 0;

    list<BiNode *> currLevel;
    list<BiNode *> nextLevel;

    currLevel.push_back(&head);
    (*pulHeight)++;
    *pulWidth = currLevel.size();

    while(!currLevel.empty()) {
        list<BiNode *>::iterator itr = currLevel.begin();
        if((*itr)->left != NULL) {
            nextLevel.push_back((*itr)->left);
        }

        if((*itr)->right != NULL) {
            nextLevel.push_back((*itr)->right);
        }

        currLevel.erase(itr);

        if(currLevel.empty()) {

            currLevel.swap(nextLevel);
            // ����������
            if (!currLevel.empty()) {
                // �߶�����
                (*pulHeight)++;

                // ���¿��
                if (*pulWidth < currLevel.size()) {
                    *pulWidth = currLevel.size();
                }
            }
        }
    }

    return 0;
}
