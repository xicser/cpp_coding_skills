#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char GeWei[13][4] = {"as", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char JinWei[13][4] = {"as", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};


int _power13(int index)
{
    int res = 1;
    for (int i = 0; i < index; i++) {
        res *= 13;
    }
    return res;
}


int getIndex(char *digit, int *which)
{
    for (int i = 1; i <=12; i++) {
        if (strcmp(digit, GeWei[i]) == 0) {
            *which = 1;
            return i;
        }
    }

    for (int i = 1; i <=12; i++) {
        if (strcmp(digit, JinWei[i]) == 0) {
            *which = 2;
            return i;
        }
    }

    return -1;
}

void _10convertTo13(int dec)
{
    if (dec == 0) {
        printf("tret\n");
        return;
    }

    if (dec % 13 == 0) {
         printf("%s\n", JinWei[dec / 13]);

    } else if (dec < 13) {
        printf("%s\n", GeWei[dec]);

    } else {
        printf("%s ", JinWei[dec / 13]);
        printf("%s\n", GeWei[dec % 13]);
    }
}
void _13convertTo10(char *str)
{
    if (strcmp(str, "tret") == 0) {
        printf("0\n");
        return;
    }

    if (strlen(str) == 3) {
        int index_tmp, which;
        index_tmp = getIndex(str, &which);

        if (which == 1) {
            printf("%d\n", index_tmp);
        } else {
            printf("%d\n", index_tmp * 13);
        }

    } else {
        int dec_sum = 0;
        char tmp_str1[4], tmp_str2[4];
        int index_tmp, which;

        strncpy(tmp_str1, str, 3);
        tmp_str1[3] = 0;
        index_tmp = getIndex(tmp_str1, &which);
        dec_sum += index_tmp * 13;

        strncpy(tmp_str2, str + 4, 3);
        tmp_str2[3] = 0;
        index_tmp = getIndex(tmp_str2, &which);
        dec_sum += index_tmp;

        printf("%d\n", dec_sum);
    }
}

int main()
{
    int N;
    char inputStr[50];

    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {
        gets(inputStr);
        if (isdigit(inputStr[0])) {
            _10convertTo13(atoi(inputStr));
        } else {
            _13convertTo10(inputStr);
        }
    }

    return 0;
}
