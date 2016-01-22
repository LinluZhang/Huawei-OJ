
#include "OJ.h"

/*
����: ����һ�������������һ������ڵ㣬���������а������������ڵ㡣
	  ����Ϊ��ָ��������Ϊ�쳣�����ⲻ���ǽڵ�ֵ��ȵ������

����: ListNode* pListHead  ��������
      ListNode* pInsertNode �²���ڵ�

���: ListNode* pListHead  ��������

����: ��������ڵ㷵������ͷָ�룬�����쳣���ؿ�ָ��
*/
ListNode* InsertNodeToList(ListNode* pListHead, ListNode* pInsertNode) {

    if(pListHead == NULL || pInsertNode == NULL) {
        return (ListNode*)NULL;
    }

    // ʹ��ͷ���
    ListNode * root = new ListNode();
    root->m_pNext = pListHead;
    ListNode * p = root;

    // ��Ҫ�����Ԫ�ص�ǰ��
    while(p->m_pNext != NULL && p->m_pNext->m_nKey < pInsertNode->m_nKey) {
        p = p->m_pNext;
    }

    pInsertNode->m_pNext = p->m_pNext;
    p->m_pNext = pInsertNode;

    return root->m_pNext;
}

