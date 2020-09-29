#include <stdio.h>
#include <stdlib.h>

#define NUM_BLACK_HOLE (6174)

static int cmp (const void *a, const void *b)
{
    int *A = (int *)a;
    int *B = (int *)b;

    if (*A > *B) return -1;
    else return 1;
}

int bits[4];
int main()
{
    int steps = 0;
    int N;
    int num_big, num_little;

    scanf("%d", &N);

    bits[0] = N / 1000 % 10;
    bits[1] = N / 100 % 10;
    bits[2] = N / 10 % 10;
    bits[3] = N / 1 % 10;

    if (bits[0] == bits[1] &&
        bits[1] == bits[2] &&
        bits[2] == bits[3]) {
        printf("%04d - %04d = 0000\n", N, N);
        return 0;
    }

    do {
        bits[0] = N / 1000 % 10;
        bits[1] = N / 100 % 10;
        bits[2] = N / 10 % 10;
        bits[3] = N / 1 % 10;
        qsort(bits, 4, sizeof(int), cmp);

        num_big = bits[0] * 1000 + bits[1] * 100 + bits[2] * 10 + bits[3];
        num_little = bits[3] * 1000 + bits[2] * 100 + bits[1] * 10 + bits[0];

        N = num_big - num_little;
        printf("%04d - %04d = %04d\n", num_big, num_little, N);

        steps++;

    } while (N != NUM_BLACK_HOLE);


//    printf("%d\n", steps);


    return 0;
}
