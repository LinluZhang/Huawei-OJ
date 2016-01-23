#include <stdlib.h>
#include <iostream>
#include <set>
#include "oj.h"

using namespace std;

// ����head�ظ��Ľڵ�ɾ����ֻ���µ�һ��
bool isDuplicateNode(strNode * head, int data) {
    if(head == NULL) {
        return false;
    }
    strNode * next = head->pstrNext;


    while(next != NULL) {
        if(next->data == data) {
            return true;
        }

        next = next->pstrNext;
    }

    return false;
}


/*
����:  ����һ������ͷ�ڵ�ĵ�������(����Ľڵ���С��100),ɾ�������������ظ��Ľڵ㣨�ظ��Ľڵ�ȫ��ɾ������ʣ��Ľڵ������š�

����:   pstrIn�� ����һ������ͷ�ڵ�ĵ�������

���:   pstrOut��ɾ�������ظ��Ľڵ���������е�����(����ͷ�ڵ�,�����һ���ڵ���ڴ��Ѿ�����)��

����:

ʾ��:
�����������������Ϊ 6,7,8,8,9,10,6
������������������Ӧ���� 10,9,7

*/



int iChanProcess(strNode * pstrIn,strNode * pstrOut) {

    if(pstrIn == NULL || pstrOut == NULL) {
        return -1;
    }

    strNode * p = pstrIn;

    set<int> intSet;

    while(p != NULL) {
        // ������ظ�Ԫ��
        if(intSet.find(p->data) != intSet.end()) {
            p = p->pstrNext;
            continue;
        }

        bool dup = isDuplicateNode(p, p->data);

        // ������ظ�Ԫ��,���Ҳ����ظ�Ԫ�ؼ�����
        if(dup == true) {
            intSet.insert(p->data);
            p = p->pstrNext;
            continue;
        }

        // ����һ���µĽ��
        strNode * node = (strNode *)malloc(sizeof(strNode));
        node->data = p->data;

        // ���뵽node�ڵ�֮��
        node->pstrNext = pstrOut->pstrNext;
        pstrOut->pstrNext = node;


        p = p->pstrNext;

    }

    intSet.clear();

    // ��һ������к�̽�㣬����̽��ɾ�����Ѻ������ֵ���ڵ�һ�������
    if(pstrOut->pstrNext != NULL) {
        strNode * next = pstrOut->pstrNext;
        pstrOut->pstrNext = next->pstrNext;
        pstrOut->data = next->data;
        next->pstrNext = NULL;
        free(next);
    }



    return 0;
}

/* �ͷ����� */
void vFreeChan(strNode * pstrChan) {

    if(pstrChan == NULL) {
        return ;
    }

    do {
        strNode * prev = pstrChan;
        pstrChan = pstrChan->pstrNext;
        prev->pstrNext = NULL;
        free(prev);

    } while(pstrChan != NULL);

    return;
}
