#include <stdio.h>
#include <stdlib.h>




char toLowerCase(char c)
{
    return c + 32;
}


char input[255];
int main()
{
    char char_tmp;

    while (1) {

        scanf("%c", &char_tmp);
        if (char_tmp != '\n') {

            //大写字母统一转小写
            if ('A' <= char_tmp && char_tmp <= 'Z') {
                input[(int)toLowerCase(char_tmp)]++;
            } else if ('A' <= char_tmp && char_tmp <= 'z') {
                input[(int)char_tmp]++;
            }

        } else break;
    }

    int max = -1;
    int max_index;
    for (int i = 0; i < 255; i++) {
        if (('A' <= i && i <= 'Z') ||
            ('a' <= i && i <= 'z')) {

            if (input[i] > max) {
                max = input[i];
                max_index = i;
            }

        }
    }

    printf("%c %d\n", max_index, input[max_index]);
    return 0;
}
