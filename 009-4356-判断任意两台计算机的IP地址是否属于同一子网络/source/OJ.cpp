#include <stdlib.h>
#include <string.h>
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

int getIP(char * chpcIP, unsigned int * npcIP) {
    // ��¼�����λ��
    int i = 0;
    // ��ǰ��IP���ֲ���
    char * temp;
    // ��ǰ��IP���ֲ��ֵĳ���
    int tempCnt = 0;
    // ��ǰ����ĵڶ��ٸ�IP����
    int cntIP = 0;
    // IP�ַ����ĳ���
    int lenIP = strlen(chpcIP);

    for (i = 0; i <= lenIP; i++) {
        // ˵��������ĳ���ֵĽ���λ��
        if((chpcIP[i] == '.') || (chpcIP[i] == '\0')) {
            // �����ڴ�
            temp = (char*)malloc(tempCnt * sizeof(char));
            // ��ֵ
            memcpy(temp, chpcIP + i - tempCnt, tempCnt);
            // �����ַ���ת������
            npcIP[cntIP] = atoi(temp);
            // �ͷ��ڴ�ռ�
            free(temp);
            // ��¼��һ��IP���ֲ���
            cntIP++;
            // ���ȹ�0
            tempCnt = 0;
        } else {
            tempCnt++;
        }
    }
    return 0;
}

int IsSameSubNetwork(char * pcIp1, char * pcIp2, char * pcSubNetworkMask) {
    /*������ʵ�ֹ���*/
    int flag = 1;
    int i = 0;
    unsigned int ip1[4] = {0};
    unsigned int ip2[4] = {0};
    unsigned int mask[4] = {0};
    getIP(pcIp1, ip1);
    getIP(pcIp2, ip2);
    getIP(pcSubNetworkMask,mask);

    for (i = 0; i < 4; i++) {
        if ((ip1[i] & mask[i]) != (ip2[i] & mask[i])) {
            flag = 0;
        }
    }
    return flag;
}
