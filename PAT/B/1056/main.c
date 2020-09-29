#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    int sum = 0;
    int N;
    scanf("%d", &N);
    int array[N];


    for (i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i != j) {
                sum += array[i] * 10 + array[j];
            }
        }

    }

    printf("%d\n", sum);
    return 0;
}
