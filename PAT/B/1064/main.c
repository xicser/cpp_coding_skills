#include <stdio.h>
#include <stdlib.h>


int output[50];
int getNum(char *str)
{
    int sum = 0;
    for (int i = 0; str[i] != 0; i++) {
        sum += str[i] - 48;
    }
    return sum;
}
int main()
{
    int N;
/*
123 899 51 998 27 33 36 12

123 899 51 998 27 33 36 12
*/
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char tmp_str[10];
        getchar();
        scanf("%s", tmp_str);
        output[getNum(tmp_str)]++;
    }

    int count = 0;
    int count_cur = 0;
    for (int i = 0; i < 50; i++) {
        if (output[i]) {
            count++;
        }
    }
    printf("%d\n", count);
    for (int i = 0; i < 50; i++) {
        if (output[i]) {
            printf("%d", i);
            count_cur++;
            if (count_cur == count) printf("\n");
            else printf(" ");
        }
    }

    return 0;
}
