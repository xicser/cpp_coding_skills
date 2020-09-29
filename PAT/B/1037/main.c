#include <stdio.h>
#include <stdlib.h>


/*
P          A
10.16.27   14.1.28

Galleon.Sickle.Knut

十七个银西可(Sickle)兑一个加隆(Galleon)，二十九个纳特(Knut)兑一个西可，很容易。
*/
int main()
{
    int P_Galleon, P_Sickle, P_Knut;
    int A_Galleon, A_Sickle, A_Knut;
    scanf("%d.%d.%d %d.%d.%d", &P_Galleon, &P_Sickle, &P_Knut, &A_Galleon, &A_Sickle, &A_Knut);

    int sum_P = 29 * P_Sickle + P_Knut + 29 * 17 * P_Galleon;
    int sum_A = 29 * A_Sickle + A_Knut + 29 * 17 * A_Galleon;
    int res;

    if (sum_P > sum_A) {
        printf("-");
    }
    res = abs(sum_P - sum_A);

    printf("%d.", res / (29 * 17));
    res = res % (29 * 17);
    printf("%d.", res / 29);
    res = res % 29;
    printf("%d", res);

    return 0;
}
