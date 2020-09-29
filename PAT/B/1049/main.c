#include <stdio.h>
#include <stdlib.h>




int main()
{
    int N;
    scanf("%d", &N);
    double sum=0;
    for(int i=0;i<N;i++)
    {
        double t=0;
        scanf("%lf", &t);
        sum+=t*(i+1)*(N-i);
    }
    printf("%.2f",sum);
}


/*
4
0.1 0.2 0.3 0.4
*/
//int main()
//{
//    int N;
//    scanf("%d", &N);
//    double input[N];
//
//    for (int i = 0; i < N; i++) {
//        scanf("%lf", &input[i]);
//    }
//
//    double sum = 0;
//    for (int i = 0; i < N; i++) {
//
//        for (int j = 1; j <= N - i; j++) { //遍历各个长度
//
//            for (int k = i; k < j + i; k++) {
//                sum += input[k];
//            }
//        }
//    }
//
//    printf("%.2lf", sum);
//
//    return 0;
//}
