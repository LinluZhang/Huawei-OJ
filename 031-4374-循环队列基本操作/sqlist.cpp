/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     :
  Version       :
  Author        :
  Created       : 2012/03/12
  Last Modified :
  Description   :
  Function List :

  History       :
  1.Date        : 2012/03/12
    Author      :
    Modification: Created file

******************************************************************************/
#include <stdlib.h>

#define MAXSIZE 50

struct strqueue {
    int queue[MAXSIZE];
    int head; /* ��ͷ */
    int tail; /* ��β */
    int num;  /* ��Ԫ�ظ��� */
};

bool initqueue(struct strqueue *s) { /* ��ʼ�����У�����0��ʾʧ�ܣ�����1��ʾ�ɹ� */

    if(s == NULL) {
        return 0;
    }

    s->head = -1;
    s->tail = -1;
    s->num = 0;

    for(int i = 0; i < MAXSIZE; i++) {
        s->queue[i] = 0;
    }

    return 1;
}

bool enqueue(struct strqueue *s, int x) { /* �����У�����0��ʾʧ�ܣ�����1��ʾ�ɹ� */

    if(s == NULL) {
        return 0;
    }

    int result = 0;

    if(s->num == 0) {
        s->tail = (s->tail + 1)/MAXSIZE;
        s->queue[s->tail] = x;
        s->head = s->tail;
        s->num++;
        result = 1;
    } else if(s->num == MAXSIZE) {
        result = 0;
    } else {
        s->tail = (s->tail + 1)%MAXSIZE;
        s->queue[s->tail] = x;
        s->num++;
        result = 1;
    }

    return result;
}

bool dequeue(struct strqueue *s, int *x) { /* �����У�����0��ʾʧ�ܣ�����1��ʾ�ɹ� */

    if(s == NULL || x == NULL) {
        return 0;
    }

    bool result = 0;

    if(s->num == 0) {
        result = 0;
    } else {
        *x = s->queue[s->head];
        s->queue[s->head] = 0;
        s->head = (s->head + 1)%MAXSIZE;
        s->num--;

        if(s->num == 0) {
            s->head =-1;
            s->tail = -1;
        }

        result = 1;
    }


    return result;
}

int gethead(struct strqueue *s) { /* ��ö���ͷ��ֵ */
    if(s == NULL || s->num == 0) {
        return -1;
    }

    int head = 0;
    head = s->queue[s->head];

    return head;
}


int gettail(struct strqueue *s) { /* ��ö���β��ֵ */
    if(s == NULL || s->num == 0) {
        return -1;
    }

    int tail = 0;
    tail = s->queue[s->tail];

    return tail;
}

int getqueuelenth(struct strqueue *s) { /* ��ö��г��� */

    if(s == NULL) {
        return 0;
    }

    int lenth = 0;
    lenth = s->num;

    return lenth;
}

bool search(struct strqueue *s, int x) { /* �ڶ����в���x�Ƿ���ڣ�������ڷ���1�����򷵻�0 */

    if(s == NULL || s->num == 0) {
        return 0;
    }

    bool result = 0;

    int p = s->head;
    for(int i = 0; i < s->num; i++) {
        if(s->queue[(p + i)%MAXSIZE] == x) {
            result = 1;
            break;
        }
    }

    return result;
}
