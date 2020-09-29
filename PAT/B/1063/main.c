#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    double max = -1;
    int N;

    scanf("%d", &N);

    for (int i = 0 ; i < N; i++) {
        double a, b;
        double value;
        scanf("%lf %lf", &a, &b);
        value = sqrt(a * a + b * b);
        if (value > max) {
            max = value;
        }
    }


    printf("%.2lf\n", max);
    return 0;
}
