#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long up;
    long long down;
} Fraction;


long long my_abs(long long a)
{
    if (a < 0) return a * -1;
    else return a;
}

//最大公约数
long long gcd (long long a, long long b)
{
    if (b == 0) return a;
    else return gcd(b, a % b);
}
void Simplification(Fraction fra)
{
    if (fra.down == 0) {  //分母为0
        printf("Inf");
        return;
    }

    if (fra.up == 0) {
        printf("0");
        return;
    }

    if (fra.down < 0) {
        fra.up *= -1;
        fra.down *= -1;
    }

    if (my_abs(fra.up) == my_abs(fra.down)) //分子分母绝对值相同
    {
        if (fra.up < 0) printf("(%lld)", fra.up / fra.down);
        else printf("%lld", fra.up / fra.down);
    }
    else if (my_abs(fra.up) < my_abs(fra.down))
    {
        long long gcd_num = gcd(my_abs(fra.up), my_abs(fra.down));
        fra.up /= gcd_num;
        fra.down /= gcd_num;

        if (fra.up < 0) printf("(%lld/%lld)", fra.up, fra.down);
        else printf("%lld/%lld", fra.up, fra.down);
    }
    else
    {
        long long abs_up, abs_down;
        long long gcd_num = gcd(my_abs(fra.up), my_abs(fra.down));
        fra.up /= gcd_num;
        fra.down /= gcd_num;

        abs_up = my_abs(fra.up);
        abs_down = my_abs(fra.down);

        if (abs_up % abs_down == 0) {
            if (fra.up < 0) printf("(%lld)", fra.up / fra.down);
            else printf("%lld", fra.up / fra.down);
            return;
        }

        if (fra.up < 0) {
            printf("(-%lld %lld/%lld)", abs_up / abs_down,
               abs_up % abs_down, fra.down);
        } else {
            printf("%lld %lld/%lld", abs_up / abs_down,
               abs_up % abs_down, fra.down);
        }
    }
}

Fraction plus (Fraction fra1, Fraction fra2)
{
    Fraction frac_tmp;

    frac_tmp.down = fra1.down * fra2.down;
    frac_tmp.up = fra1.up * fra2.down + fra1.down * fra2.up;

    return frac_tmp;
}

Fraction minus (Fraction fra1, Fraction fra2)
{
    Fraction frac_tmp;

    frac_tmp.down = fra1.down * fra2.down;
    frac_tmp.up = fra1.up * fra2.down - fra1.down * fra2.up;

    return frac_tmp;
}

Fraction multi (Fraction fra1, Fraction fra2)
{
    Fraction frac_tmp;

    long long gcd_num = gcd(my_abs(fra1.up), my_abs(fra1.down));
    fra1.up /= gcd_num;
    fra1.down /= gcd_num;

    gcd_num = gcd(my_abs(fra2.up), my_abs(fra2.down));
    fra2.up /= gcd_num;
    fra2.down /= gcd_num;

    frac_tmp.down = fra1.down * fra2.down;
    frac_tmp.up = fra1.up * fra2.up;

    return frac_tmp;
}

void devide (Fraction fra1, Fraction fra2)
{
    Fraction frac_tmp;
    long long swap_tmp;

    if (fra2.up == 0) {
        printf("Inf\n");
        return;
    }

    if (fra1.up == 0) {
        printf("0\n");
        return;
    }

    swap_tmp = fra2.down;
    fra2.down = fra2.up;
    fra2.up = swap_tmp;

    long long gcd_num = gcd(my_abs(fra1.up), my_abs(fra1.down));
    fra1.up /= gcd_num;
    fra1.down /= gcd_num;

    gcd_num = gcd(my_abs(fra2.up), my_abs(fra2.down));
    fra2.up /= gcd_num;
    fra2.down /= gcd_num;


    frac_tmp.down = fra1.down * fra2.down;
    frac_tmp.up = fra1.up * fra2.up;

    Simplification(frac_tmp);
    printf("\n");
}

int main(void)
{
    Fraction fra1 ,fra2, result;
    scanf("%lld/%lld %lld/%lld", &fra1.up, &fra1.down, &fra2.up, &fra2.down);

    //+
    Simplification(fra1), printf(" + "), Simplification(fra2);
    printf(" = ");
    result = plus(fra1 ,fra2);
    Simplification(result);
    printf("\n");

    //-
    Simplification(fra1), printf(" - "), Simplification(fra2);
    printf(" = ");
    result = minus(fra1 ,fra2);
    Simplification(result);
    printf("\n");

    //*
    Simplification(fra1), printf(" * "), Simplification(fra2);
    printf(" = ");
    result = multi(fra1 ,fra2);
    Simplification(result);
    printf("\n");

    //除法
    Simplification(fra1), printf(" / "), Simplification(fra2);
    printf(" = ");
    devide(fra1 ,fra2);

    return 0;
}
