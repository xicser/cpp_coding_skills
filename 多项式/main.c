#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int ratio; //系数
    int index; //指数
} Item_t;

//加法输出数组
int polynomial_plus_out[1100];

//乘法输出数组
int polynomial_product_out[1000005];


int main()
{
    int zero_flag;
    int M, N;

    scanf("%d", &M);
    Item_t polynomial_A[M];  //多项式A
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &polynomial_A[i].ratio, &polynomial_A[i].index);
    }
    scanf("%d", &N);
    Item_t polynomial_B[N];  //多项式B
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &polynomial_B[i].ratio, &polynomial_B[i].index);
    }

//计算乘法
    Item_t polynomial_product[M * N]; //乘法输出数组
    int index_product = 0; //下标
    for (int i = 0; i < M; i++) { //相乘
        for (int j = 0; j < N; j++) {
            polynomial_product[index_product].index = polynomial_A[i].index + polynomial_B[j].index; //指数相加
            polynomial_product[index_product].ratio = polynomial_A[i].ratio * polynomial_B[j].ratio; //系数相乘
            index_product++;
        }
    }
    //合并同类项
    for (int i = 0; i < index_product; i++) {
        polynomial_product_out[polynomial_product[i].index] += polynomial_product[i].ratio;
    }
    //输出
    zero_flag = 0;
    for (int i = 1000005 - 1; i >= 0; i--) {
        if (polynomial_product_out[i]) {
            printf("%d %d ", polynomial_product_out[i], i);
            zero_flag = 1;
        }
    }
    if (!zero_flag) printf("0 0\n"); //全是0的处理
    else printf("\n");


//计算加法
    for (int i = 0; i < M; i++) {
        polynomial_plus_out[polynomial_A[i].index] += polynomial_A[i].ratio;
    }
    for (int i = 0; i < N; i++) {
        polynomial_plus_out[polynomial_B[i].index] += polynomial_B[i].ratio;
    }
    //输出
    zero_flag = 0;
    for (int i = 1100 - 1; i >= 0; i--) {
        if (polynomial_plus_out[i]) {
            printf("%d %d ", polynomial_plus_out[i], i);
            zero_flag = 1;
        }
    }
    if (!zero_flag) printf("0 0\n"); //全是0的处理
    else printf("\n");

    return 0;
}
