#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char str1[300];
char str2[300];

int flag[1000] = {0};

/*
7_This_is_a_test
_hs_s_a_es
*/
void toHigherCase(char *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if ('a' <= str[i] && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
}

int isExist(char c, char *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (c == str[i]) return 1;
    }
    return 0;
}
int main()
{
    gets(str1);
    gets(str2);
    toHigherCase(str1);
    toHigherCase(str2);


    for (int i = 0; str1[i] != 0; i++) {
        if (!isExist(str1[i], str2) && flag[(int)str1[i]] == 0)  {
            printf("%c", str1[i]);
            flag[(int)str1[i]] = 1;
        }
    }


    printf("\n");
    return 0;
}
