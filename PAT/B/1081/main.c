#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
如果密码合法，输出Your password is wan mei.；
//  如果密码太短，不论合法与否，都输出Your password is tai duan le.；
//  如果密码长度合法，但存在不合法字符，则输出Your password is tai luan le.；
//  如果密码长度合法，但只有字母没有数字，则输出Your password needs shu zi.；
如果密码长度合法，但只有数字没有字母，则输出Your password needs zi mu.。
*/


static int is_num(char c)
{
    if ('0' <= c && c <= '9') return 1;
    return 0;
}
static int is_Alpha(char c)
{
    if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) return 1;
    return 0;
}

void process(char *str)
{
    int num[4] = {0}; //数字, 字母, '.', 其他

    for (int i = 0; str[i] != 0; i++) {
        if (is_num(str[i])) {
            num[0]++;
        } else if (is_Alpha(str[i])) {
            num[1]++;
        } else if (str[i] == '.') {
            num[2]++;
        } else {
            num[3]++;
        }
    }

    if (num[0] + num[1] + num[2] + num[3] < 6) {
        printf("Your password is tai duan le.\n");
    } else if (num[3]) {
        printf("Your password is tai luan le.\n");
    } else if (num[0] == 0 && num[1] != 0 && num[3] == 0) {
        printf("Your password needs shu zi.\n");
    } else if (num[0] != 0 && num[1] == 0 && num[3] == 0) {
        printf("Your password needs zi mu.\n");
    } else printf("Your password is wan mei.\n");
}

int main()
{
    char passwd[100];
    int N;
    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; i++) {
        gets(passwd);
        process(passwd);
    }
    return 0;
}
