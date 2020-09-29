#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int index;  //指数
    int ratio;  //系数
} Iterm_t;

Iterm_t iterm[10000];
int iterm_count = 0;


int cmp (const void *a, const void *b)
{
    Iterm_t *itermA = (Iterm_t *)a;
    Iterm_t *itermB = (Iterm_t *)b;
    if (itermA->index > itermB->index) return -1;
    return 1;
}

/*
3 4 -5 2 6 1 -2 0
*/
int main()
{
    int num;
    int first_flag = 1;
    int zero_count = 0;
    while (scanf("%d", &num) != EOF) {  //输入
        if (first_flag) {
            first_flag = 0;
            iterm[iterm_count].ratio = num;
        } else if (!first_flag) {
            first_flag = 1;
            iterm[iterm_count++].index = num;
        }
    }

    if (iterm[0].index == 0) {
        printf("0 0\n");
        return 0;
    }

    for (int i = 0; i < iterm_count; i++) { //计算
        if (iterm[i].index == 0) {
            iterm[i].ratio = 0;
            iterm[i].index = 0;
            zero_count++;
        } else {
            iterm[i].ratio *= iterm[i].index;
            iterm[i].index -= 1;
        }
    }
    iterm_count -= zero_count;

    qsort(iterm, iterm_count, sizeof(Iterm_t), cmp);

    for (int i = 0; i < iterm_count; i++) { //输出
        printf("%d %d", iterm[i].ratio, iterm[i].index);
        if (iterm_count - 1 == i) printf("\n");
        else printf(" ");
    }

    return 0;
}
