#include <iostream>
#include <math.h>
#include <stdio.h>


using namespace std;

bool isPrime(int n)
{
    if (n <= 1) return false;
    int sqr = (int) sqrt(1.0 * n);

    for (int i = 2; i <= sqr; i++) {
        if (n % i == 0) return false;
    }
    return true;

}

int main()
{
    int cnt;
    int M, N;

    scanf("%d %d", &M, &N);

    cnt = 0;
    for (int i = M; cnt < N; i++) {
        if (isPrime(i)) {
            printf("%d\n", i);
            cnt++;
        }
    }

    return 0;
}
