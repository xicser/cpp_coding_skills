#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char PaliNum(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}
void reverse(char *str)
{
    char swap_tmp;
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        swap_tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = swap_tmp;
    }
}
void bigNumPlus(char *str1, char *str2)
{
    int flag = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len_max = len1 > len2 ? len1 : len2;
    len_max += 1;

    //反转一下, 方便处理
    reverse(str1);
    reverse(str2);

    //补0, 方便处理进位
    if (len1 > len2) {
        strcat(str1, "0");
        for (int i = 0; i < len1 - len2 + 1; i++) {
            strcat(str2, "0");
        }
    } else if (len1 < len2) {
        strcat(str2, "0");
        for (int i = 0; i < len2 - len1 + 1; i++) {
            strcat(str1, "0");
        }
    } else {
        strcat(str1, "0");
        strcat(str2, "0");
    }

//    printf("str1 = %s\n", str1);
//    printf("str2 = %s\n", str2);
    for (int i = 0; i < len_max - 1; i++) {
        str1[i] -= 48;
        str2[i] -= 48;
    }

    for (int i = 0; i < len_max - 1; i++) {
        int res = str1[i] + str2[i];
        if (i == len_max - 2 && res >= 10) { //最后一位进位了
            flag = 1;
        }
        str1[i] = res % 10;
        str1[i + 1] += res / 10;
    }

    for (int i = 0; i < len_max - 1; i++) {
        str1[i] += 48;
    }

    if (flag) {
        str1[len_max] = 0;
    } else {
        str1[len_max - 1] = 0;
    }
    reverse(str1);
//    printf("str1 = %s\n", str1);
}

char num[10050];
char num_tmp[10005];
int main()
{
    int step = 0;
    gets(num);

    while (!PaliNum(num)) {
        step++;
        if (step > 10) {
            printf("Not found in 10 iterations.\n");
            return 0;
        }

        printf("%s + ", num);
        strcpy(num_tmp, num);
        reverse(num_tmp);
        printf("%s = ", num_tmp);
        bigNumPlus(num_tmp, num);
        printf("%s\n", num_tmp);
        strcpy(num, num_tmp);
    }

    printf("%s is a palindromic number.\n", num);

    return 0;
}
