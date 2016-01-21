
#include "OJ.h"

/*
����: ������̼��㳵��
ԭ�ͣ�
    int CalcSpeedOfCar(int iCurrentMileage, int * piCarSpeed);

���������
    int pcCurrentMileage:��ǰ�����(Ϊ�Գ���)(pcCurrentMileage �� 999999)

����ֵ��
    �����ٶ�(����/Сʱ)
*/

int IsSymmetricNumber(unsigned int speed) {
    unsigned int v = speed;
    unsigned int t = 0;
    while(v != 0) {
        t = t*10 + v%10;
        v /= 10;
    }

    if(speed == t) {
        return 1;
    } else {
        return 0;
    }
}

int CalcSpeedOfCar(int iCurrentMileage, int * piCarSpeed) {

    if(iCurrentMileage < 1 || iCurrentMileage > 999999) {
        return 1;
    }

    unsigned int v = iCurrentMileage + 1;

    while(v <= 999999) {
        if(IsSymmetricNumber(v)) {
            break;
        }

        v++;
    }

    if(v > 999999) {
        *piCarSpeed = 0;
        return 1;
    }

    *piCarSpeed = (v - iCurrentMileage) / 2;

    return 0;
}
