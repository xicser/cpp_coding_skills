#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char number[1005];
int main()
{
    int i;
    int R;
    int res;
    int B, num_len;
    int no_0_index = -1;

    scanf("%s %d", number, &B);
    num_len = strlen(number);

    if (number[0] == '0') { //检查有没有前导0
        for (int i = 0; number[i] != 0; i++) {
            if (number[i] != '0') {
                no_0_index = i;
                break;
            }
        }

        if (no_0_index == -1) { //如果全为0
            printf("0\n");
            return 0;
        }

        for (int i = no_0_index; number[i] != 0; i++) {
            number[i - no_0_index] = number[i];
        }
        num_len -= no_0_index;
    }

    //转为数字
    for (int i = 0; i < num_len; i++) {
        number[i] -= 48;
    }

    if (num_len == 1) {  //针对只有一位的数
        printf("%d %d", number[0] / B, number[0] % B);
        return 0;
    }

    //开始模拟除法
    if (number[0] >= B) {
        res = number[0] / B;
        printf("%d", res);
        R = number[0] % B;
        number[0] = R;
    }
    for (i = 1; i < num_len; i++) {
        res = (number[i] + number[i - 1] * 10) / B;
        printf("%d", res);
        R = (number[i] + number[i - 1] * 10) % B;
        number[i] = R;
    }
    printf(" %d", R);

    return 0;
}
