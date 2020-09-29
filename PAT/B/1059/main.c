#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct {
    int rank;
    int is_awd_exist;
    int is_exist;
} Student_t;


Student_t students[10005] = {0};


int isPrime(int n)
{
    if (n <= 1) return 0;
    int sqr = (int) sqrt(1.0 * n);

    for (int i = 2; i <= sqr; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main()
{
    int N, K;

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int tmp;
        scanf("%d", &tmp);
        students[tmp].rank = i;
        students[tmp].is_exist = 1;
        students[tmp].is_awd_exist = 1;
    }

    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        int tmp;
        scanf("%d", &tmp);
        if (students[tmp].is_exist) {
            if (students[tmp].is_awd_exist) {

                if (students[tmp].rank == 1) {
                    printf("%04d: Mystery Award\n", tmp);
                } else if (isPrime(students[tmp].rank)) {
                    printf("%04d: Minion\n", tmp);
                } else {
                    printf("%04d: Chocolate\n", tmp);
                }

                students[tmp].is_awd_exist = 0;

            } else {
                printf("%04d: Checked\n", tmp);
            }
        } else {
            printf("%04d: Are you kidding?\n", tmp);
        }
    }

    return 0;
}
