#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
5 3
1001 992 0    233  6
8    0   2018 0    2008
36   18  0    1024 4
*/


typedef struct {
    int order;
    int value;
} Mooncake_t;


int cmp (const void *a, const void *b)
{
    Mooncake_t *cakeA = (Mooncake_t *)a;
    Mooncake_t *cakeB = (Mooncake_t *)b;

    if (cakeA->value > cakeB->value) {
        return -1;
    } else if (cakeA->value == cakeB->value) {
        if (cakeA->order < cakeB->order) {
            return -1;
        } else return 1;
    }
    return 1;
}

int main()
{
    int M, N;

    scanf("%d%d", &M, &N);

    Mooncake_t mooncake[M];
    memset(mooncake, 0, sizeof(Mooncake_t) * M);

    for (int i = 0; i < N; i++) {
        for (int j = 0 ; j < M; j++) {
            int tmp;
            scanf("%d", &tmp);
            mooncake[j].value += tmp;
            mooncake[j].order = j + 1;
        }
    }


    qsort(mooncake, M, sizeof(Mooncake_t), cmp);

    int max = mooncake[0].value;
    int count = 0;
    int current = 0;
    printf("%d\n", max);
    for (int j = 0 ; j < M; j++) {
        if (mooncake[j].value == max) {
            count++;
        }
    }
    for (int j = 0 ; j < M; j++) {
        if (mooncake[j].value == max) {
            current++;
            if (current == count) printf("%d", mooncake[j].order);
            else printf("%d ", mooncake[j].order);
        }
    }

    printf("\n");

    return 0;
}
