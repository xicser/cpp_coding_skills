#include <stdio.h>
#include <stdlib.h>




typedef struct {
    int id;
    int x;
    int y;
    double distance;
} Athlete;

static int cmp (const void *a, const void *b)
{
    Athlete *first = (Athlete *)a;
    Athlete *second = (Athlete *)b;

    if (first->distance > second->distance) return 1;
    return -1;
}


int main()
{
    int N;
    scanf("%d", &N);
    Athlete athletes[N];

    for (int i = 0; i < N; i++) {
        scanf("%d%d%d", &athletes[i].id, &athletes[i].x, &athletes[i].y);
        athletes[i].distance = athletes[i].x * athletes[i].x + athletes[i].y * athletes[i].y;
    }

    qsort(athletes, N, sizeof(Athlete), cmp);

    printf("%04d %04d\n", athletes[0].id, athletes[N - 1].id);
    return 0;
}
