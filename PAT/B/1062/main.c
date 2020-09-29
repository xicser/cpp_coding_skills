#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int up, down;
} Fraction;

Fraction findBig(Fraction frac, int K)
{
    Fraction frac_tmp;

    if (K * frac.up % frac.down == 0) {
        frac_tmp.up = K * frac.up / frac.down - 1;
    } else {
        frac_tmp.up = K * frac.up / frac.down;
    }

    frac_tmp.down = K;

    return frac_tmp;
}

Fraction findLittle(Fraction frac, int K)
{
    Fraction frac_tmp;

    frac_tmp.up = K * frac.up / frac.down + 1;
    frac_tmp.down = K;

    return frac_tmp;
}

//最大公约数
int gcd (int a, int b)
{
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int is_simplest(Fraction frac)
{
    if (gcd (frac.up, frac.down) == 1) return 1;
    else return 0;
}

void swp(Fraction *frac1, Fraction *frac2)
{
    Fraction frac_tmp;
    if (frac1->up * frac2->down > frac1->down * frac2->up) {
        frac_tmp = *frac1;
        *frac1 = *frac2;
        *frac2 = frac_tmp;
    }
}

// 7/18 13/20 12
Fraction fracs_output[1000];
int output_index = 0;
int main()
{
    int K;
    Fraction frac_a, frac_b;
    Fraction frac_little, frac_big, frac_index;

    scanf("%d/%d %d/%d %d", &frac_a.up, &frac_a.down, &frac_b.up, &frac_b.down, &K);

    swp(&frac_a, &frac_b);

    frac_little = findLittle(frac_a, K);
    frac_big = findBig(frac_b, K);


    for (frac_index = frac_little; frac_index.up <= frac_big.up; frac_index.up++) {
        if (is_simplest(frac_index)) {
            fracs_output[output_index++] = frac_index;
        }
    }

    for (int i = 0; i < output_index; i++) {
        printf("%d/%d", fracs_output[i].up, fracs_output[i].down);
        if (i == output_index - 1) printf("\n");
        else printf(" ");
    }

    return 0;
}
