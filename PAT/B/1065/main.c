#include <stdio.h>
#include <stdlib.h>


/*
3
index value

11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333
*/
int pairs[111111] = {-1};

int input[111111];
int output[111111];
int output_index = 0;



int isExist(int a, int *array, int len)
{
    for (int i = 0; i < len; i++) {
        if (a == array[i]) {
            return 1;
        }
    }
    return 0;
}
static int cmp(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b) return 1;
    else return -1;
}


int main()
{
    int person;


    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int tmp1, tmp2;
        scanf("%d%d", &tmp1, &tmp2);
        pairs[tmp1] = tmp2;
        pairs[tmp2] = tmp1;
    }

    int M;
    scanf("%d", &M);
    if (N == 0 && M == 0) return 0;
    for (int i = 0; i < M; i++) {
        scanf("%d", &input[i]);
    }

    for (int i = 0; i < M; i++) {
        person = input[i];
        if (pairs[person] != -1) { //这个人有情侣

            int lover = pairs[person]; //情侣的ID
            if (!isExist(lover, input, M)) { //看这个人的情侣在不在
                output[output_index++] = person;
            }
        } else {
            output[output_index++] = person;
        }
    }

    //排序
    qsort(output, output_index, sizeof(int), cmp);

    printf("%d\n", output_index);
    for (int i =0; i < output_index; i++) {
        if (i != output_index - 1) printf("%05d ", output[i]);
        else printf("%05d", output[i]);
    }


    return 0;
}
