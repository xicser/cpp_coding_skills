#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isLegal(char *str)
{
    int has_dot = 0;    //记录是否有小数点
    int has_dash = 0;
    int dot_cnt = 0;
    int dash_cnt = 0;
    int after_dot = 0;
    int len = strlen(str);

    //只能由数字和'.'组成, 且'.'不能超过1个
    for (int i = 0; i < len; i++) {
        if (str[i] != '.' && str[i] != '-' && (str[i] > '9' || str[i] < '0')) {
            return 0;
        }
        if (str[i] == '.') {
            has_dot = 1;
            dot_cnt++;
            if (dot_cnt > 1) {
                return 0;
            }
        }
        if (str[i] == '-') {
            has_dash = 1;
            dash_cnt++;
            if (dash_cnt > 1) {
                return 0;
            }
        }
    }

    if (has_dash && str[0] != '-') {
        return 0;
    }
    if (len == 1 && str[0] == '-') {
        return 0;
    }


    if (has_dot) {
        for (int i = 0; i < len; i++) {
            if (str[i] == '.') { // '.'后面如果有数字, 则位数不能超过2

//                if (str[i + 1] == 0) { //231.
//                    return 0;
//                }

                if (str[i - 1] > '9' || str[i - 1] < '0') { //-.2
                    return 0;
                }

                for (int j = i + 1; str[j]; j++) { //231.45
                    after_dot++;
                }
                if (after_dot > 2) {
                    return 0;
                }
                break;
            }
        }
    }

    return 1;
}

int main()
{
    double average = 0;
    int count = 0;
    int N;
    char numer[1000];

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", numer);

//        printf("num = %s\n", numer);

        if (!isLegal(numer)) {
            printf("ERROR: %s is not a legal number\n", numer);
        } else {
            double tmp;
            sscanf(numer, "%lf", &tmp);
//            printf("tmp = %lf\n", tmp);

            if (-1000 <= tmp && tmp <= 1000) {
                average += tmp;
                count++;
            } else {
                printf("ERROR: %s is not a legal number\n", numer);
            }
        }
    }

    if (count == 0) {
        printf("The average of 0 numbers is Undefined\n");
    } else {
        if (count == 1) {
            printf("The average of %d number is %.2lf", count, average / count);
        } else {
            printf("The average of %d numbers is %.2lf", count, average / count);
        }
    }

    return 0;
}
