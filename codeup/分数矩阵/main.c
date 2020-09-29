#include <stdio.h>
#include <stdlib.h>

//typedef struct {
//    float up;
//    float down;
//} Fraction;
/*
1/1 1/2 1/3
1/2 1/1 1/2
1/3 1/2 1/1

1/1 1/2 1/3 1/4 1/5
1/2 1/1 1/2 1/3 1/4
1/3 1/2 1/1 1/2 1/3
1/4 1/3 1/2 1/1 1/2
1/5 1/4 1/3 1/2 1/1

*/
/*
int input[100000];
int input_index = 0;
float sum[100000];

int main()
{
    int N_tmp, N;
    float frac_array_up = 1, frac_array_down;

    while (1) {
        scanf("%d", &N_tmp);
        if (N_tmp == 0) break;
        input[input_index++] = N_tmp;
    }

    for (int k = 0; k < input_index; k++) {

        N = input[k];

        sum[k] = 0;
        //构造矩阵
        for (int i = 0; i < N; i++) {
            int down_tmp;
            down_tmp = 2;
            for (int j = i - 1; j >= 0; j--) { //构造左边
                frac_array_down = down_tmp++;
                sum[k] += frac_array_up / frac_array_down;
            }
        }
        sum[k] *= 2;
        sum[k] += N;
        printf("%.2f\n", sum[k]);
    }

    return 0;
}
*/


#include<stdio.h>

int input[100000];
int input_index = 0;
float sum[100000];

int main()
{
    int i, k1 = 1,n;
    int N_tmp;

    double s=0;

    while (1) {
        scanf("%d", &N_tmp);
        if (N_tmp == 0) break;
        input[input_index++] = N_tmp;
    }

    for (int k = 0; k < input_index; k++) {
        s = 0;
        k1 =1;


        n = input[k];
        for(i=n-1;i>=0;i--,n--)
            s+=(1+(k1>1))*(double)n/k1++;

        printf("%.2lf\n",s);
    }






    return 0;

}


