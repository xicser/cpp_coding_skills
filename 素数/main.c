#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


int isPrime(int n)
{
    if (n <= 1) return 0;
    int sqr = (int) sqrt(1.0 * n);

    for (int i = 2; i <= sqr; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

//素数筛法
#define MAXN    (100)
int primes[MAXN];
int index_ = 0;
int is_prime[MAXN] = {0};

void findPrime(void)
{
    for (int i = 2; i < MAXN; i++) {
        if (!is_prime[i]) {
            primes[index_++] = i;
            for (int j = i + i; j < MAXN; j += i) {
                is_prime[j] = 1;
            }
        }
    }
}

int main()
{
    findPrime();

    for (int i = 0; i < index_; i++) {
        printf("%d ", primes[i]);
    }

    return 0;
}
