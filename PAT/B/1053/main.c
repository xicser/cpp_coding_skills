#include <stdio.h>
#include <stdlib.h>


/*
在观察期内，若存在超过一半的日子用电量低于某给定的阈值 e，则该住房为“可能空置”；
若观察期超过某给定阈值 D 天，且满足上一个条件，则该住房为“空置”。
*/
//e = 0.5
//6 0.3 0.4 0.5 0.2 0.8 0.6
int isEmpty(double *elec, int day_count, double e, int period)
{
    int count = 0;
    for (int i = 0; i < day_count; i++) {
        if (elec[i] < e) {
            count++;
        }
    }

    if (count > day_count / 2 && day_count > period) {
        return 1;  //空置
    } else if (count > day_count / 2) {
        return 2;  //可能空置
    }

    return 3;
}
void printPercentage(double num)
{
//0. 423 21
    num *= 100;
    printf("%.01lf%%", num);
}
int main()
{
    int empty_count = 0, perhaps_empty_count = 0;
    int N, D;
    double e;

    scanf("%d%lf%d", &N, &e, &D);
    for (int i = 0; i < N; i++) {
        int K;
        scanf("%d", &K);
        double elec[K];
        for (int j = 0; j < K; j++) {
            scanf("%lf", &elec[j]);
        }
        int res = isEmpty(elec, K, e, D);
        if (res == 1) {
            empty_count++;
        } else if (res == 2) {
            perhaps_empty_count++;
        }
    }

    printPercentage(1.0 * perhaps_empty_count / N);
    printf(" ");
    printPercentage(1.0 * empty_count / N);
    printf("\n");
    return 0;
}
