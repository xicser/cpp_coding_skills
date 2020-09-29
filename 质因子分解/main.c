#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//素数筛法
#define MAXN 100005
int primes[MAXN];  //存放素数的数组
int index_ = 0;
int is_prime[MAXN] = {0};

//输出hash表
int hash_out[100005];
int max_index = -1;

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
//判断一个数是不是素数
int isPrime(int n)
{
    if (n <= 1) return 0;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

//假设是个合数120
int main()
{
    int n;
    scanf("%d", &n);
    int result;

    printf("%d=", n);

    if (isPrime(n) || n == 1) { //如果输入的数已经是素数
        printf("%d\n", n);
        return 0;
    }
    //素数筛使用
    findPrime(); //先筛素数
    while (1) {

        for (int i = 0; i < n; i++) {
            //先找到第一个最小的质因子
            if (n % primes[i] == 0) {
                //printf("%d ", primes[i]);

                if (max_index < primes[i]) max_index = primes[i];
                hash_out[primes[i]]++;

                result = n / primes[i];
                break;
            }
        }

        //判断一下结果是否是素数
        if (isPrime(result)) {
            //printf("%d", result);

            if (max_index < result) max_index = result;
            hash_out[result]++;

            break;
        } else {
            n = result;
        }
    }

    //输出
    for (int i = 0; i <= max_index; i++) {
        if (hash_out[i] != 0) {

            if (hash_out[i] != 1) {
                printf("%d^%d", i, hash_out[i]);
            } else {
                printf("%d", i);
            }

            if (i == max_index) {
                printf("\n");
            } else {
                printf("*");
            }
        }
    }


    return 0;
}


/*
//    for (int i = 0; i < index_; i++) {
//        printf("%d ", primes[i]);
//    }




*/
