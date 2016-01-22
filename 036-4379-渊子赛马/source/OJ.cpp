#include <algorithm>
#include "OJ.h"

using namespace std;

/*
����:�ж�yuanzi �����Ƿ��Ӯ��yuanzi ����Ӯ�ˣ����� YES. ���򷵻� NO

���������
unsigned int num: �����������   (1<= num <=1000)
unsigned int * speed_yz: yuanzi ������ٶȣ�
unsigned int * speed_op: ���ֵ�����ٶȣ�
���������
	 	��
����ֵ��
		char * �� ���ַ�����yuanzi ����Ӯ�ˣ����� YES. ���򷵻� NO��

*/

char * IsYuanziWin(unsigned int num, unsigned int * speed_yz, unsigned int * speed_op) {

    if(num < 1 || speed_yz == NULL || speed_op == NULL) {
        return "NO";
    }

    sort(speed_yz, speed_yz + num);
    sort(speed_op, speed_op + num);

    int count = 0;

    int idx = num- 1;
    for (int i = num - 1; i >= 0; i--) {

        // ��idxλ����ǰ�ң���speedYz[i]�ٶ�������
        while (idx >= 0 && speed_yz[i] <= speed_op[idx]) {
            idx--;
        }
        // �ҵ���������Ϳ���Ӯ�ñ���
        if (idx >= 0) {
            count++;
            // speedOp����һ��Ҫ�ҵ���
            idx--;
            if (count > num / 2) {
                return "YES";
            }
        }
    }

    return "NO";
}


