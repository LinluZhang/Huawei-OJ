#include <stdlib.h>
#include "oj.h"
// ���ܣ���������������¥�ݵĳ���
// ���룺 ��
// �������
// ���أ� ��

unsigned int  GetStairNum () {

    int step = 7;
    while(true) {
        if((step % 2) == 1 && (step % 3) == 2 && (step % 5) == 4 && (step % 6) == 5) {
            break;
        }

        step += 7;
    }
    return step;
}
