#include <stdio.h>
#include <stdlib.h>



static int cmp (const void *a, const void *b);

int input[100000] = {0};
int main()
{
    int N;
    int max_index = -1;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &input[i]);
    }

    qsort(input, N, sizeof(int), cmp);


    for (int i = 0; i < N; i++) {
        if (input[i] < )
    }


    printf("%d\n", output[0]);

    return 0;
}



static int cmp (const void *a, const void *b)
{
    if (*(int *)a > *(int *)b) return 1;
    else return -1;
}
