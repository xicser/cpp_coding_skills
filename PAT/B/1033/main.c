#include <stdio.h>
#include <stdlib.h>

char str1[100005];
int str1_index = 0;

char str2[100005];

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

int shift_flag = 0;

int main()
{
    while (1) {
        char tmp_char;
        scanf("%c", &tmp_char);
        if (tmp_char != '\n') {
            if (tmp_char == '+') {
                shift_flag = 1;  //标记上档键坏了
            }
            str1[str1_index++] = tmp_char;
        } else {
            str1[str1_index] = 0;
            break;
        }
    }

    gets(str2);

    for (int i = 0; str2[i] != 0; i++) {
        if ('a' <= str2[i] && str2[i] <= 'z') {
            if (!isExist(str2[i] - 32, str1)) {
                printf("%c", str2[i]);
            }
        } else if ('0' <= str2[i] && str2[i] <= '9') {
            if (!isExist(str2[i], str1)) {
                printf("%c", str2[i]);
            }
        } else if (str2[i] == '_' || str2[i] == ',' || str2[i] == '.' || str2[i] == '-') {
            if (!isExist(str2[i], str1)) {
                printf("%c", str2[i]);
            }
        } else if ('A' <= str2[i] && str2[i] <= 'Z' && !shift_flag) {
            if (!isExist(str2[i], str1)) {
                printf("%c", str2[i]);
            }
        }
    }

    printf("\n");
    return 0;
}
