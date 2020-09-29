#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//1 2  3  2  1
//0 1  2  3  4
//len = 5
char str[500];
int main()
{
    int flag = 0;
    int i;
    int len;
    gets(str);
    len = strlen(str);

    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            flag = 1;
            break;
        }
    }

    if (flag) printf("NO\n");
    else printf("YES\n");

    return 0;
}
