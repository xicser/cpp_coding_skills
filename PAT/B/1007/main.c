#include <stdio.h>
#include <stdlib.h>


int isPrime(int k)
{
    int j;
    for ( j=2; j<k; j++ )
    {
        if(k%j==0)    // 如果不为素数返回0
        {
             return 0;
        }
        }
    return 1;    // 反之则返回1
}

int main()
{
    int i;
    int N;
    int cnt = 0;
    scanf("%d", &N);

    for (i = 2; ; i++) {
        if (isPrime(i) && isPrime(i + 2)) {
            if (i < N && (i + 2 < N)) {
                cnt++;
            }
            else break;
        }
    }

    printf("%d\n", cnt);
    return 0;
}
