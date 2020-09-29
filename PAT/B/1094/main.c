#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int isPrime(int n)
{
    if (n <= 1) return 0;
    int sqr = (int) sqrt(1.0 * n);

    for (int i = 2; i <= sqr; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}


int str2num(char *str, int len)
{
    int res;
    char buffer[100];
    strncpy(buffer, str, len);
    buffer[len] = 0;
//    printf("%s\n", buffer);
    sscanf(buffer, "%d", &res);

    return res;
}
/*
20 5
23654 98772 9
01234 56789 10
*/
int main()
{
    int flag = 0;
    int L, K;

    scanf("%d%d", &L, &K);
    char num[L + 5];
    getchar();
    gets(num);

//11 - 6 = 5
    for (int i = 0; L - i >= K; i++) {
        int tmp = str2num(num + i, K);
        if (isPrime(tmp)) {
            char out[100];
            sprintf(out, "%d", tmp);
            int len_tmp = strlen(out);
            for (int j = 0; j < K - len_tmp; j++) printf("0");
            printf("%s\n", out);

            flag = 1;
            break;
        }
    }
    if (!flag) {
        printf("404\n");
    }

    return 0;
}
