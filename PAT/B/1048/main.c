#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char A[105];
char B[105];
/*
A
  1234567   lenA = 7
B
  0082971   lenB = 5
3695Q8118

*/
int main()
{
    scanf("%s%s", A, B);
    int lenA = strlen(A);
    int lenB = strlen(B);
    int minlen = lenA > lenB ? lenB : lenA;
    int maxlen = lenA > lenB ? lenA : lenB;
    int delta = maxlen - minlen;

    if (lenA > lenB) {
        for (int i = lenB - 1; i >= 0; i--) {
            B[i + delta] = B[i];
        }
        for (int i = 0; i < delta; i++) {
            B[i] = 0 + 48;
        }
        lenB += delta;
        minlen = lenA > lenB ? lenB : lenA;
        maxlen = lenA > lenB ? lenA : lenB;
        delta = maxlen - minlen;
    }

    for (int i = lenB - 1, j = 1; i >= lenB - minlen; i--, j++) {
        if (j % 2 != 0) { //奇数位
            int res = ((A[i - delta]-48) + (B[i]-48)) % 13;
            if (res == 10) B[i] = 'J';
            else if (res == 11) B[i] = 'Q';
            else if (res == 12) B[i] = 'K';
            else B[i] = res + 48;

        } else { //偶数位
            int res = B[i] - A[i - delta];
            if (res < 0) {
                res += 10;
                B[i] = res + 48;
            } else {
                B[i] = res + 48;
            }
        }
    }

    for (int i = 0; i< lenB; i++) {
        putchar(B[i]);
    }

    return 0;
}
