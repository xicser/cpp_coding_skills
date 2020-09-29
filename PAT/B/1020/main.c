#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double store;          //库存量
    double single_price; //单价
    double total_price;  //总售价
} Mooncake_t;


static int cmp(const void *a, const void *b)
{
    Mooncake_t *mooncakeA = (Mooncake_t *)a;
    Mooncake_t *mooncakeB = (Mooncake_t *)b;
    if (mooncakeA->single_price < mooncakeB->single_price) {
        return 1;
    } else return -1;
}

int main()
{
    double sum;
    int N; //月饼种类数
    int D; //市场总需求量
    scanf("%d%d", &N, &D);
    Mooncake_t mooncakes[N];

    //读入每种月饼库存量
    for (int i = 0; i < N; i++) {
        scanf("%lf", &mooncakes[i].store);
    }

    //读入每种月饼的总售价
    for (int i = 0; i < N; i++) {
        scanf("%lf", &mooncakes[i].total_price);
        mooncakes[i].single_price = mooncakes[i].total_price / mooncakes[i].store;
    }

    //按单价由高到低排序
    qsort(mooncakes, N, sizeof(Mooncake_t), cmp);

    sum = 0;
    for (int i = 0; i < N; i++) {
        if (mooncakes[i].store <= D) {
            D = D - mooncakes[i].store;
            sum += mooncakes[i].total_price;
        } else {
            sum += mooncakes[i].single_price * D;
            break;
        }
    }

    printf("%.2f" ,sum);

//    for (int i = 0; i < N; i++) {
//        printf("%d %f %f\n", mooncakes[i].store, mooncakes[i].single_price, mooncakes[i].total_price);
//    }



    return 0;
}
















