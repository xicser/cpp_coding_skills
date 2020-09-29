#include <stdio.h>
#include <stdlib.h>


int scores[105] = {0};

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int score_tmp;
        scanf("%d", &score_tmp);
        scores[score_tmp]++;
    }

    int K;
    scanf("%d", &K);
    int searches[K];
    for (int i = 0; i < K; i++) {
        scanf("%d", &searches[i]);
    }

    for (int i = 0; i < K; i++) {
        if (i != K - 1) printf("%d ", scores[searches[i]]);
        else printf("%d\n", scores[searches[i]]);
    }

    return 0;
}


//int main()
//{
//    int N;
//    scanf("%d", &N);
//    int scores[N];
//    for (int i = 0; i < N; i++) {
//        scanf("%d", &scores[i]);
//    }
//
//    int K;
//    scanf("%d", &K);
//    int searches[K];
//    for (int i = 0; i < K; i++) {
//        scanf("%d", &searches[i]);
//    }
//
//    for (int i = 0; i < K; i++) {
//
//        int count = 0;
//        for (int j = 0; j < N; j++) {
//            if (scores[j] == searches[i]) {
//                count++;
//            }
//        }
//        printf("%d", count);
//
//        if (i != K - 1) printf(" ");
//            else printf("\n");
//    }
//
//    return 0;
//}
