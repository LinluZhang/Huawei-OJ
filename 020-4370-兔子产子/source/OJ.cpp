#include <stdlib.h>
#include "oj.h"
// ���ܣ���ȡ��nValue1���³������ٶ�����
// ���룺 nValue1Ϊ������
// �������
// ���أ���nValue1���³������ٶ�����

// ����һ����쳲��������С�����
unsigned int GetBirthRabbitNum(unsigned int  nValue1) {

    if(nValue1 < 0) {
        return 0;
    }

    if(nValue1 < 3) {
        return 1;
    }

    return GetBirthRabbitNum(nValue1 - 1) + GetBirthRabbitNum(nValue1 - 2);
}
