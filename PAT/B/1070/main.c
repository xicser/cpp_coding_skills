#include <stdio.h>
#include <stdlib.h>

int cmp (const void *a, const void *b)
{
    if (*(double *)a > *(double *)b) return 1;
    return -1;
}

int main()
{
    double res = 0;
    int N;

    scanf("%d", &N);
    double array[N];
    for (int i = 0; i < N; i++) {
        scanf("%lf", &array[i]);
    }

    qsort(array, N, sizeof(double), cmp);

    for (int i = 0; i < N - 1; i++) {
        array[i + 1] = (array[i] + array[i + 1]) / 2;
    }
    printf("%d\n", (int)array[N - 1]);


    return 0;
}
