#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main(void)
{
    int flag;
    char radix[25];
    char number1[25];
    char number2[25];
    char output[25];
    int output_index = 0;
    int len1, len2, r_len, len;
    gets(radix);
    gets(number1);
    gets(number2);
    r_len = strlen(radix);
    len1 = strlen(number1);
    len2 = strlen(number2);
    reverse(radix);
    reverse(number1);
    reverse(number2);

    //补0, 方便处理最后一个进位
    if (len1 > len2) {
        len = len1 + 1;
        strcat(number1, "0");
        for (int i = 0; i <= len1 - len2; i++) {
            strcat(number2, "0");
        }
    } else if (len1 < len2) {
        len = len2 + 1;
        strcat(number2, "0");
        for (int i = 0; i <= len2 - len1; i++) {
            strcat(number1, "0");
        }
    } else {
        len = len1 + 1;
        strcat(number1, "0");
        strcat(number2, "0");
    }

    //全部转换成数字, 方便处理
    for (int i = 0; i < len; i++) {
        number1[i] -= 48;
        number2[i] -= 48;
    }
    for (int i = 0 ; i < r_len; i++) {
        radix[i] -= 48;
    }

    //开始处理
    for (int i = 0 ; i < len - 1; i++) {
        int res = number1[i] + number2[i];

        if (radix[i] != 0) { //非10进制
            output[output_index++] = res % radix[i];
            number2[i + 1] += res / radix[i];

        } else { //10进制
            output[output_index++] = res % 10;
            number2[i + 1] += res / 10;
        }
    }
    output[output_index++] = number2[len - 1];


    //输出
    flag = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (flag == 0 && output[i]) {
            flag = 1;
        }
        if (flag) {
            printf("%d", output[i]);
        }
    }

    if (flag == 0) {
        printf("0");
    }

    printf("\n");

//    printf("%s\n%s\n%s", radix, number1, number2);

/*
30527
06203
415

72503
302600
514000

7201
*/

    return 0;
}
