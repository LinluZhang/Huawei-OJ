#include "ObjMgt.h"
#include <map>
#include <vector>

using namespace std;

map<long long, bool> ObjManager;

/*************************************************************************
���ܣ����ӵ�������
���룺
key1  �ⲿ�ؼ��� KEY1
key2  �ⲿ�ؼ���KEY2
key3  �ⲿ�ؼ���KEY3
�������
���أ�
      -1 :ʧ��(�����Ѿ����ڻ��������쳣)
       0 :�ɹ�
***************************************************************************/
int AddObject (unsigned int key1, unsigned int key2, unsigned int key3) {

    long long llk1 = (long long)key1;
    long long llk2 = (long long)key2;
    long long llk3 = (long long)key3;
    llk1 <<= 32;
    llk2 <<= 16;
    long long key=llk1 + llk2 + llk3;
    if(!ObjManager.count(key)) {
        ObjManager[key] = true;
    } else  {
        return -1;
    }

    return 0;
}

/********************************************************************************
���ܣ�ɾ��һ����������
���룺
      key1 �ⲿ�ؼ��� KEY1
      key2 �ⲿ�ؼ��� KEY2
      key3 �ⲿ�ؼ��� KEY3
�������
���أ���

˵����������֤����ȡֵΪ�Ϸ�ֵ��ͨ���0xFFFFFFFF, ͨ�����ʾ0~65535��Χ�ڵ�����ֵ;
      ����:key1=1,key2=2,key3= 0xFFFFFFFF����ʾɾ��key1=1,key2=2�����ж���;
           key1,key2,key3ȡֵȫΪ0xFFFFFFFFʱ,��ʾɾ�����ж���
*********************************************************************************/
void DeleteObject (unsigned int key1, unsigned int key2, unsigned int key3) {
    map<long long, bool>::iterator it;
    unsigned int myKey1, myKey2, myKey3;
    vector<long long> keyShouldRrase;
    for(it = ObjManager.begin(); it != ObjManager.end(); it++) {
        long long key = (*it).first;
        myKey1= (key & 0xFFFF00000000) >> 32;
        myKey2 = (key & 0xFFFF0000) >> 16;
        myKey3 = key & 0xFFFF;
        if((0xFFFFFFFF == key1 || myKey1 == key1)
                && (0xFFFFFFFF == key2 || myKey2 == key2)
                && (0xFFFFFFFF == key3 || myKey3 == key3)) {
            keyShouldRrase.push_back(key);
        }
    }
    for(int i=0; i< keyShouldRrase.size(); i++) {
        ObjManager.erase(keyShouldRrase[i]);
    }

    return ;
}

/********************************************************************************
���ܣ���ѯ���������Ƿ����
���룺
      key1 �ⲿ�ؼ��� KEY1
      key2 �ⲿ�ؼ��� KEY2
      key3 �ⲿ�ؼ��� KEY3
�������
���أ�
      0��������
      1������
**********************************************************************************/
int IsObjectExist (unsigned int key1, unsigned int key2, unsigned int key3) {
    long long llk1 = (long long)key1;
    long long llk2 = (long long)key2;
    long long llk3 = (long long)key3;
    llk1 <<= 32;
    llk2 <<= 16;
    long long key=llk1 + llk2 + llk3;
    if(ObjManager.count(key)) {
        return 1;
    }

    return 0;
}

/******************************************************************************************************
Description     ������ж���
Prototype       void Clear();
Input Param     ��
Output Param    ��
Return Value    ��

********************************************************************************************************/
void Clear(void) {
    ObjManager.clear();
    return;
}
