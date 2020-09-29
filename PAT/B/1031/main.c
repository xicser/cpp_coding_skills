#include <stdio.h>
#include <stdlib.h>

char id_num[20];

char M[] = "10X98765432";
int power[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};


int main()
{
    int N;
    int sum;
    int is_all_pass = 1;

    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {
        gets(id_num);

        //先看看前17位是否全为数字
        int j;
        for (j = 0 ; j < 17; j++) {
            if ('0' > id_num[j] || id_num[j] > '9') {
                break;
            }
        }
        if (j != 17) {
            is_all_pass = 0;
            printf("%s\n", id_num);
            continue;
        }

        sum = 0;
        //计算前17为校验和
        for (j = 0; j < 17; j++) {
            sum += power[j] * (id_num[j] - 48);
        }
        sum %= 11;
        if (id_num[17] != M[sum]) {
            is_all_pass = 0;
            printf("%s\n", id_num);
        }
    }

    if (is_all_pass) printf("All passed\n");

    return 0;
}
