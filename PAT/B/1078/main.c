#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
C
TTTTThhiiiis isssss a   tesssst CAaaa as
*/
typedef struct {
    char c;
    int times;
} strNo_repe_t;

//12345
int str2num(char *str, int len)
{
    int res = 0;
    int k = 1;
    for (int i = len - 1; i >= 0; i--, k *= 10) {
        res += (str[i] - 48) * k;
    }
    return res;
}


strNo_repe_t strNo_repe[1005] = {0};
int strNo_index = 0;
int main()
{
    char type;
    char str[1005];

    scanf("%c", &type);
    getchar();
    gets(str);
    int len = strlen(str);

    //压缩
    if (type == 'C') {
        strNo_repe[strNo_index].c = str[0];
        strNo_repe[strNo_index].times = 1;
        for (int i = 1; i < len; i++) { //先统计每个字符出现的次数
            if (str[i] == str[i - 1]) {
                strNo_repe[strNo_index].times++;
            } else {
                strNo_index++;
                strNo_repe[strNo_index].c = str[i];
                strNo_repe[strNo_index].times = 1;
            }
        }
        strNo_index++;

        for (int i = 0; i < strNo_index; i++) {
            if (strNo_repe[i].times != 1) {
                printf("%d%c", strNo_repe[i].times, strNo_repe[i].c);
            } else {
                printf("%c", strNo_repe[i].c);
            }
        }
        return 0;
    }

/*
D
5T2h4is i5s a3 te4st CA3a as10Z
*/
    //解压
    for (int i = 0; i < len; ) {
        if ('0' <= str[i] && str[i] <= '9') {
            int len = 0;
            for (int j = i; '0' <= str[j] && str[j] <= '9'; j++) {
                len++;
            }
            int repeat = str2num(&str[i], len);
//            printf("%d ", repeat);
            for (int j = 0; j < repeat; j++) {
                printf("%c", str[i + len]);
            }
            i += len + 1;
        } else {
            printf("%c", str[i]);
            i++;
        }
    }
    printf("\n");
}
/*
TTTTThhiiiis isssss a   tesssst CAaaa asZZZZZZZZZZ
TTTTThhiiiis isssss a   tesssst CAaaa asZZZZZZZZZZ
*/
