#include <stdio.h>
#include <stdlib.h>


//2 2 0 0 0 3 0 0 1 0
//0 1 2 3 4 5 6 7 8 9

static int cmp (const void *a, const void *b)
{
    int *A, *B;
    A = (int *)a;
    B = (int *)b;

    if (*A > *B) return 1;
    else return -1;
}


int main()
{
    int which;
    int input[10];
    int num[100];
    int index = 0;

    for (int i = 0 ; i < 10; i++ ){
        scanf("%d", &input[i]);
        for (int j = 0; j < input[i]; j++) {
            num[index++] = i;
        }
    }

    qsort(num, index, sizeof(int), cmp);
    for (int i = 0 ; i < index; i++ ) {
        if (num[i] != 0) {
            which = i;
            printf("%d", num[which]);
            break;
        }
    }

    for (int i = 0 ; i < index; i++ ) {
        if (i != which) {
            printf("%d", num[i]);
        }
    }

    printf("\n");
    return 0;
}
