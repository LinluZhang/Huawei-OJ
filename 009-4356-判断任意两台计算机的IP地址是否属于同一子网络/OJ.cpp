
#include "OJ.h"


/*
����: �ж���̨�����IP��ַ��ͬһ�����硣
ԭ�ͣ�
    int IsSameSubNetwork(char * pcIp1, char * pcIp2, char * pcSubNetworkMask);

���������
    char * pcIP1: �����1��IP��ַ����ʽ����192.168.0.254����
    char * pcIP2: �����2��IP��ַ����ʽ����192.168.0.1����
    char * pcSubNetworkMask: �������룬��ʽ����255.255.255.0����

����ֵ��
    0��IP1��IP2������ͬһ�����磻
    1��IP1��IP2����ͬһ�����磻
*/
/*
int IsSameSubNetwork(char * pcIp1, char * pcIp2, char * pcSubNetworkMask) {
    for(int i = 0; i < 4; i++) {
        if((pcIp1[i]&pcSubNetworkMask[i]) != (pcIp2[i]&pcSubNetworkMask[i])) {
            return 1;
        }
    }

    return 0;
}

*/

