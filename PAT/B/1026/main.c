#include <stdio.h>
#include <stdlib.h>

#define CLK_TCK (100)

int main()
{
    int hh, mm;
    double C1, C2;
    double seconds_tmp;

    int seconds;

    scanf("%lf %lf", &C1, &C2);

    seconds_tmp = 1.0 *(C2 - C1) / CLK_TCK;
    seconds = (int)(seconds_tmp + 0.5); //四舍五入

//    printf("%d\n", seconds);

    hh = seconds / 3600;
    seconds = seconds % 3600;

    mm = seconds / 60;
    seconds = seconds % 60;

    printf("%02d:%02d:%02d\n", hh, mm, seconds);
    return 0;
}
