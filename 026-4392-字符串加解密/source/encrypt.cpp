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
#include <string.h>
#include <stdio.h>

//1����������ַ������мӽ��ܣ��������
//
//2���ܷ���Ϊ��
//��������Ӣ����ĸʱ���ø�Ӣ����ĸ�ĺ�һ����ĸ�滻��ͬʱ��ĸ�任��Сд,����ĸaʱ���滻ΪB����ĸZʱ���滻Ϊa��
//������������ʱ��Ѹ����ּ�1����0�滻1��1�滻2��9�滻0��
//�����ַ������仯��
//
//3�����ܷ���Ϊ���ܵ�����̡�

int Encrypt (char password[], char result[]) {
    if(password == NULL || result == NULL) {
        return -1;
    }

    int i = 0;
    while(password[i] != '\0') {
        if(password[i] >= '0' && password[i] <= '9') {
            result[i] = (char)((password[i] - '0' + 1 )%10 + '0');
        } else if(password[i] >= 'a' && password[i] <= 'z') {
            result[i] = (char)((password[i] - 'a' + 1 )%26 + 'A');
        }   else if(password[i] >= 'A' && password[i] <= 'Z') {
            result[i] = (char)((password[i] - 'A' + 1 )%26 + 'a');
        } else {
             result[i] = password[i];
        }

        i++;
    }

    result[i] = '\0';

    return 0;
}

int unEncrypt (char result[], char password[]) {

    if(password == NULL || result == NULL) {
        return -1;
    }

    int i = 0;
    while(result[i] != '\0') {
        if(result[i] >= '0' && result[i]<= '9') {
            password[i] = (char)((result[i] - '0' - 1 + 10 )%10 + '0');
        } else if(result[i] >= 'a' && result[i] <= 'z') {
            password[i] = (char)((result[i] - 'a' - 1 + 26 )%26 + 'A');
        }   else if(result[i] >= 'A' && result[i] <= 'Z') {
            password[i] = (char)((result[i] - 'A' - 1 + 26 )%26 + 'a');
        } else {
             password[i] = result[i];
        }

        i++;
    }

    password[i] = '\0';

    return 0;
}




