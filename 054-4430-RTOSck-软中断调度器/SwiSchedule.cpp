/******************************************************************************

Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

******************************************************************************
File Name     :
Version       :
Author        :
Created       : 2010/3
Last Modified :
Description   :
Function List :

History       :
1.Date        : 2010/3
Author      :
Modification: Created file

******************************************************************************/
#include <cstdio>
#include <queue>
#include <cstring>
#include <map>

using namespace std;

// ����һ����������
typedef void (* PROC_FUN)(void);

// ����һ�����ṹ��
typedef struct Node {
    int swiId;      // ����ж�ID
    int prio;       // ���ж����ȼ�
    PROC_FUN proc;  // ����ж�ִ�к�������

    // �����Ƚ�������
    friend bool operator < (Node n1, Node n2) {
        return n1.prio > n2.prio;
    }
} SwitchNode;

// ȫ�����ȶ��У�����prio��С��������
priority_queue<SwitchNode> globleSwiQueue;
// ȫ������ж�ӳ��
map<int, SwitchNode> globleSwiMap;
// ���е�ID
int runningId;

/*************************************************************************************************
����˵�����������ж�
���������
      swiId�� �������ж�ID��
	  prio��  �������ж����ȼ���
      proc��  �������жϴ�������
�����������
����ֵ  ���ɹ�����0�� �����������-1
**************************************************************************************************/
int SwiCreate(unsigned int swiId, unsigned int prio, void (* proc)(void)) {

    // �ж�����������Ƿ�Ϸ�
    if(prio < 0 || prio > 31 || proc == NULL || globleSwiMap.count(swiId) != 0) {
        return -1;
    } else {
        // ����������
        SwitchNode node;
        node.swiId = swiId;
        node.prio = prio;
        node.proc = proc;
        globleSwiMap[swiId] = node;
    }

    return 0;
}

/*************************************************************************************************
����˵�������жϼ���
���������swiId�� ���������ж�ID
�����������
����ֵ  ���ɹ�����0�� �����������-1
**************************************************************************************************/
int SwiActivate(unsigned int swiId) {

    // û�ж�Ӧ�����ж�Id
    if(globleSwiMap.count(swiId) == 0) {
        return -1;
    }

    // �ж�Ӧ�����ж�ID�����ж϶������
    globleSwiQueue.push(globleSwiMap[swiId]);

    // �����swiId�ڵ�����ж�
    while(!globleSwiQueue.empty()) {
        SwitchNode node = globleSwiQueue.top();
        if(runningId != node.swiId) {
            int oldRunningId = runningId;
            runningId = node.swiId;
            node.proc();
            runningId = oldRunningId;
            globleSwiQueue.pop();
        } else {
            break;
        }
    }

    return 0;
}

/*************************************************************************************************
����˵����������е���Ϣ
�����������
�����������
����ֵ  ����
**************************************************************************************************/
void Clear(void) {
    runningId = -1;
    globleSwiMap.clear();
    while(!globleSwiQueue.empty()) {
        globleSwiQueue.pop();
    }
}
