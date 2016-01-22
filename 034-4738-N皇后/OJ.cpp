#include <stdlib.h>
#include <memory.h>
#include <math.h>

#include "OJ.h"

// ����K��Ԫ���Ƿ���Է�
bool check(int *board, int k) {
    for (int i = 0; i < k; i++) {
        if (abs(k - i) == abs(board[k] - board[i]) || board[i] == board[k]) {
            return false;
        }
    }

    return true;
}
/*
����: ������8�ʺ󷽰��ĸ�����
���룺
    ��
���أ�
    int������8�ʺ󷽰��ĸ���
*/

int PlaceQueenMethodNum(int n) {

    if(n < 1) {
        return 0;
    }

    int *board = (int *)malloc(sizeof(int)*n);
    memset(board, -1, sizeof(int)*n);

    int sum = 0;
// ��i������
    int i = 0;
    while (i >= 0) {
        board[i]++;
        while (board[i] < n && !check(board, i)) {
            board[i]++;
        }

        if (board[i] < n) {
            // ������һ��Ԫ�ش�������
            if (i == n - 1) {
                sum++;
            } else {
                // ������һ����
                i++;
                // ���ڵ�һ��λ��
                board[i] = -1;
            }
        } else {
            // ���ص���һ������
            i--;
        }
    }

    return sum;
}
