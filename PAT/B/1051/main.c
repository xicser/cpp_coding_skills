#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct {
    double a;
    double b;
} Complex_t;

int main()
{
    Complex_t complexA, complexB, complexRes;
    double R1, P1, R2, P2;
    double accuracy = 0.01;

    scanf("%lf%lf%lf%lf", &R1, &P1, &R2, &P2);

    complexA.a = R1 * cos(P1);
    complexA.b = R1 * sin(P1);

    complexB.a = R2 * cos(P2);
    complexB.b = R2 * sin(P2);

    //下面相乘
    complexRes.a = complexA.a * complexB.a - complexA.b * complexB.b;
    complexRes.b = complexA.a * complexB.b + complexA.b * complexB.a;

    if (fabs(complexRes.a) < accuracy) complexRes.a = 0;
    if (fabs(complexRes.b) < accuracy) complexRes.b = 0;

    if (complexRes.b >= 0) {
        printf("%.2lf+%.2lfi", complexRes.a, complexRes.b);
    } else {
        printf("%.2lf%.2lfi", complexRes.a, complexRes.b);
    }



    return 0;
}
