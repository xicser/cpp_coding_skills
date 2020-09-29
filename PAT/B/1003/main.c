#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char str_input[10][100];


//判断是否完整包含PAT
int isContainsFullPAT(char *str)
{
    int i;
    //先看有没有'P'
    for (i = 0; str[i] != 0; i++) {
        if (str[i] == 'P') break;
    }
    if (i == strlen(str)) {
        return 0;
    }
    //先看有没有'P'
    for (i = 0; str[i] != 0; i++) {
        if (str[i] == 'A') break;
    }
    if (i == strlen(str)) {
        return 0;
    }
    //先看有没有'P'
    for (i = 0; str[i] != 0; i++) {
        if (str[i] == 'T') break;
    }
    if (i == strlen(str)) {
        return 0;
    }

    return 1;
}


//判断str中是否含有其他字符
int isContainsOtherCharacter(char *str)
{
    int i;
    for (i = 0; str[i] != 0; i++) {
        if (str[i] == 'P' || str[i] == 'A' || str[i] == 'T') {
            continue;
        }
        else return 1;
    }
    return 0;
}
//判断str中是否含有*PAT*
int isContainsPAT(char *str)
{
    int i, j;
    for (i = 0; str[i] != 0; i++) {
        if (str[i] == 'P' && str[i + 1] == 'A' && str[i + 2] == 'T') {
            //再判断其他的字符是不是都是'A'
            for (j = 0; str[j] != 0; j++) {
                if (j == i || j == i + 1 || j == i + 2) {
                    continue;
                }
                if (str[j] != 'A') return 0;
            }

            return 1;
        }
    }
    return 0;
}
//判断str中是否含有*PAAT*
int isContains_PAAT_(char *str)
{
    int i, j;
    for (i = 0; str[i] != 0; i++) {
        if (str[i] == 'P' && str[i + 1] == 'A' && str[i + 2] == 'A' &&  str[i + 3] == 'T') {
            //再判断其他的字符是不是都是'A'
            for (j = 0; str[j] != 0; j++) {
                if (j == i || j == i + 1 || j == i + 2 || j == i + 3) {
                    continue;
                }
                if (str[j] != 'A') return 0;
            }
            return 1;
        }
    }

    return 0;
}


int main()
{
    int i;
    int num;
    scanf("%d", &num);
    getchar(); //吸收回车符

    for (i = 0; i < num; i++) {
        gets(str_input[i]);
    }

    for (i = 0; i < num; i++) {
        if (strlen(str_input[i]) == 0) {
            printf("NO\n");
            continue;
        }
        if (!isContainsFullPAT(str_input[i])) {
            printf("NO\n");
            continue;
        }
        if (isContainsOtherCharacter(str_input[i])) {
            printf("NO\n");
            continue;
        }
        if (isContainsPAT(str_input[i])) {
            printf("YES\n");
        } else if (isContains_PAAT_(str_input[i])) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
