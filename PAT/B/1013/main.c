#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 1000005

int primes[MAXN];
int primes_index = 0;

int find_primes[MAXN] = {0};

void findPrimes(void)
{
    for (int i = 2; i < MAXN; i++) {
        if (find_primes[i] == 0) {
            primes[primes_index++] = i;
        }
        for (int j = i + i; j < MAXN; j += i) {
            find_primes[j] = 1;
        }
    }
}

/*
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103

*/
int main()
{
    int print_cnt = 0;
    int M, N;

    scanf("%d %d", &M, &N);

    findPrimes();

    for (int i = M - 1; i < N; i++) {
        printf("%d", primes[i]);
        print_cnt++;
        if (print_cnt % 10 != 0 && i + 1 < N) printf(" ");
        else printf("\n");
    }

    return 0;
}

