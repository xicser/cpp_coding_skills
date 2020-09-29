#include <stdio.h>
#include <stdlib.h>


int z[100], num = 0;
//11
int main()
{
    int A, B, radix, result;

    scanf("%d%d%d", &A, &B, &radix);
    result = A + B;

    do {
        z[num++] = result % radix;
        result /= radix;

    } while (result != 0);

    for (int i = num - 1; i >= 0; i--) {
        printf("%d", z[i]);
    }

    return 0;
}
