#include <stdlib.h>
#include "oj.h"
/*
����: �ַ�����ɾ��ָ���ַ�

����: in, c

���: out

����: 0

*/

int removechars(char *in, char c, char *out) {

    if(in == NULL || out == NULL) {
        return 0;
    }

    char * p = in;
    char * q = out;

    while(*p != '\0') {
        if(*p != c) {
            *q = *p;
            q++;
        }
        p++;
    }

    *q = '\0';

    return 0;
}
