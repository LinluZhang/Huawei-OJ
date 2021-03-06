#include <set>
#include <vector>
#include <map>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>


using namespace std;

/******************************************************************************

  Copyright (C), 2001-2012, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     : FindSimilarWord.cpp
  Version       :
  Author        :
  Created       : 2012/09
  Last Modified :
  Description   :
  Function List :

  History       :
  1.Date        : 2012/09
    Author      :
    Modification: Created file

******************************************************************************/
map<string, set<string> > dic;

void quickSort(string * srr, int begPos, int endPos ) {
    if(begPos < endPos) {
        int pivot = (*srr)[begPos];
        int lo = begPos;
        int hi = endPos;

        while(lo < hi) {
            while(lo < hi && (*srr)[hi] >= pivot) {
                hi--;
            }
            (*srr)[lo] = (*srr)[hi];

            while(lo < hi && (*srr)[lo] <= pivot) {
                lo++;
            }

            (*srr)[hi] = (*srr)[lo];
        }

        (*srr)[lo] = pivot;
        quickSort(srr, begPos, lo - 1);
        quickSort(srr, lo + 1, endPos);
    }

}

bool isWord(char* word) {
    int i = 0;
    while(*word != '\0' && isalpha(*word) && islower(*word)) {
        i++;
        word++;
    }

    if(*word == '\0' && i > 0)  {
        return true;
    } else {
        return false;
    }
}

/******************************************************************************
原    型：int AddOneWord (char* Word);
功    能：在字典中增加一个单词
输入参数：
          Word 单词字符串，调用者保证Word指针不为空，指向的是合法单词
输出参数：
          无
返回值：
        -1 失败（单词在字典中已存在等情况）
        0  成功
********************************************************************************/

int AddOneWord (char* Word) {
    // 字符串是NULL，或者是非法的字符串
    if(Word == NULL || !isWord(Word)) {
        return -1;
    }

    string valueStr(Word);
    string key(Word);
    // 排序
    quickSort(&key, 0, key.length() - 1);

    if(dic[key].count(valueStr) == 0) {
        dic[key].insert(valueStr);
        return 0;
    } else {
        return -1;
    }

}

/******************************************************************************
原    型：int FindSimilarWordNum (char* Word);
功    能：查找指定单词在字典中的兄弟单词个数
输入参数：
          Word 指定单词字符串，调用者保证Word指针不为空，指向的是合法单词
输出参数：
          无
返回值：
          返回指定单词在字典中的兄弟单词总个数。如果不存在兄弟单词，返回0
*******************************************************************************/
int FindSimilarWordNum (char* Word) {

    // 字符串是NULL，或者是非法的字符串
    if(Word == NULL || !isWord(Word)) {
        return 0;
    }

    string key(Word);
    quickSort(&key, 0, key.length() - 1);

    if(dic[key].size() == 0) {
        return 0;
    } else {
        string str(Word);
        set<string> valueSet = dic[key];
        if(valueSet.count(str) != 0) {
            return valueSet.size() - 1;
        } else {
            return valueSet.size();
        }
    }
}

/******************************************************************************
原    型：int FindOneSimilarWord (char* Word, int Seq, char* SimilarWord);
功    能：查找指定单词的指定序号的兄弟单词，指定序号指字典中兄弟单词按字典顺序
          排序后的序号（从1开始）
输入参数：
          Word 指定单词字符串，调用者保证Word指针不为空，指向的是合法单词
          Seq 指定序号（大于等于1）
输出参数：
          SimilarWord 返回兄弟单词字符串，指针不为空，指向的内存由调用者预先分配，
          占51个字节长度，输出的兄弟单词必须紧跟’\0’结束。如果不存在指定序号的
          兄弟单词，输出空串。
返回值：
          -1 失败（如果不存在指定序号的兄弟单词，返回失败）
          0  成功
*******************************************************************************/
int FindOneSimilarWord (char* Word, int Seq, char* SimilarWord) {

    // 字符串是NULL，或者是非法的字符串
    if(Word == NULL || !isWord(Word)  || Seq < 1) {
        return 0;
    }

    string key(Word);
    quickSort(&key, 0, key.length() - 1);

    map<string, set<string> >::iterator mapItr = dic.find(key);
    // 如果没有这样子的键
    if(mapItr == dic.end()) {
        SimilarWord[0] = '\0';
        return -1;
    }
    // 找到这样子的键
    else {
        set<string> valueSet = dic[key];
        // 不存在指定序号的兄弟单词
        if(Seq > valueSet.size()) {
            SimilarWord[0] = '\0';
            return - 1;
        }

        vector<string> wv(valueSet.begin(), valueSet.end());
        sort(wv.begin(), wv.end());

        int cnt = 0;
        vector<string>::iterator setItr = wv.begin();
        while(cnt < Seq && setItr != wv.end()) {

            string value = *setItr;
            // 如果不是本身
            if(value.compare(Word) != 0) {
                cnt++;

                if(cnt == Seq) {
                    break;
                }
            }
            setItr++;
        }

        // 没有找到
        if(setItr == wv.end()) {
            return -1;
        }

        // 找到了
        string value = *setItr;
        strcpy(SimilarWord, value.c_str());

        return 0;
    }
}

/******************************************************************************
原    型：void ClearAllWords(void);
功    能：清空字典中所有单词
输入参数：
          无
输出参数：
          无
返回值：
          无

*******************************************************************************/
void ClearAllWords(void) {
    dic.erase(dic.begin(), dic.end());
}
/*
void printDic() {
    map<string, set<string> >::iterator mapItr = dic.begin();
    for(; mapItr != dic.end(); mapItr++) {
        cout << mapItr->first << ">";
        for(set<string>::iterator setItr = mapItr->second.begin(); setItr != mapItr->second.end(); setItr++) {
            cout << (*setItr) << " ";
        }
        cout << endl;
    }
}
*/
