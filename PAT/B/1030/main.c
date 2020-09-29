#include <stdio.h>
#include <stdlib.h>

/*
10 8
2 3 20 4 5 1 6 7 8 9
*/
int cmp(const void *a, const void *b)
{
    if (*(double *)a > *(double *)b) return 1;
    return -1;
}
int main()
{
    int N;
    double p;

    scanf("%d %lf", &N, &p);
    double input[N];

    for (int i = 0; i < N; i++) {
        scanf("%lf", &input[i]);
    }
    qsort(input, N, sizeof(double), cmp);

    double m;
    int count;
    int bigest_count = 0;
    for (int i = 0; i < N; i++) {

        count = 1;
        m = input[i];
        for (int j = i + 1; j < N; j++) {
            if (m * p >= input[j]) {
                count++;
            } else {
                if (count > bigest_count) {
                    bigest_count = count;
                }
                break;
            }
        }
        if (count > bigest_count) {
            bigest_count = count;
        }
    }
    printf("%d\n", bigest_count);

    return 0;
}
