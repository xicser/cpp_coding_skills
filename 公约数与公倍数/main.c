#include <stdio.h>
#include <stdlib.h>


//最大公约数
int gcd (int a, int b)
{
    if (b == 0) return a;
    else return gcd(b, a % b);
}

//最小公倍数
int lcm (int a, int b)
{
    int d = gcd(a, b);
    return a * b / d;
}



int main()
{
    printf("%d\n", gcd(25, 4));
    return 0;
}
