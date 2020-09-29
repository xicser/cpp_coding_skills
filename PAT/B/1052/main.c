#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char hands[50][200];
int hands_index = 0;

char eyes[50][200];
int eyes_index = 0;

char mouths[50][200];
int mouth_index = 0;

char str_in[200];
int main()
{
    int K;
    int i, j, len;
    gets(str_in); //输入手
    for (i = 0 ; str_in[i]; ) {
        if (str_in[i] == '[') {
            len = 0;
            for (j = i + 1; str_in[j] != ']'; j++) {
                len++;
            }
            strncpy(hands[hands_index++], &str_in[i + 1], len);
            i += len + 2;
        } else {
            i++;
        }
    }
    gets(str_in); //输入眼
    for (i = 0 ; str_in[i]; ) {
        if (str_in[i] == '[') {
            len = 0;
            for (j = i + 1; str_in[j] != ']'; j++) {
                len++;
            }
            strncpy(eyes[eyes_index++], &str_in[i + 1], len);
            i += len + 2;
        } else {
            i++;
        }
    }
    gets(str_in); //输入口
    for (i = 0 ; str_in[i]; ) {
        if (str_in[i] == '[') {
            len = 0;
            for (j = i + 1; str_in[j] != ']'; j++) {
                len++;
            }
            strncpy(mouths[mouth_index++], &str_in[i + 1], len);
            i += len + 2;
        } else {
            i++;
        }
    }

    scanf("%d", &K);
    for (i = 0; i < K; i++) {
        int left_hand, left_eye, mouth, right_eye, right_hand;
        scanf("%d%d%d%d%d", &left_hand, &left_eye, &mouth, &right_eye, &right_hand);
        if (left_hand > hands_index || right_hand > hands_index ||
            left_eye > eyes_index || right_eye > eyes_index ||
            mouth > mouth_index) {
            printf("Are you kidding me? @\\/@\n");
        } else if (left_hand < 1 || left_eye < 1 || mouth < 1 || right_eye < 1 || right_hand < 1) {
            printf("Are you kidding me? @\\/@\n");
        } else {
            printf("%s", hands[left_hand - 1]);
            printf("(%s", eyes[left_eye - 1]);
            printf("%s", mouths[mouth - 1]);
            printf("%s)", eyes[right_eye - 1]);
            printf("%s\n", hands[right_hand - 1]);
        }
    }

    return 0;
}
