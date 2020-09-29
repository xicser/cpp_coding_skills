#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valid = 0;
    int M, X, Y;
    int abilityA, abilityB;
    double abilityC;

    scanf("%d%d%d", &M, &X, &Y);

    for (abilityA = 99; abilityA >= 10; abilityA--) {
        abilityB = (abilityA / 1 % 10) * 10 + (abilityA / 10 % 10);
        abilityC = 1.0 * abs(abilityA - abilityB) / X;

        if (abilityC * Y == abilityB) {
            valid = 1;

            printf("%d ", abilityA);
            if (abilityA == M) printf("Ping ");
            else if (abilityA > M) printf("Cong ");
            else if (abilityA < M) printf("Gai ");

            if (abilityB == M) printf("Ping ");
            else if (abilityB > M) printf("Cong ");
            else if (abilityB < M) printf("Gai ");

            if (abilityC == M) printf("Ping");
            else if (abilityC > M) printf("Cong");
            else if (abilityC < M) printf("Gai");

            break;
        }
    }

    if (!valid) {
        printf("No Solution\n");
    }

    return 0;
}
