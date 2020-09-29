#include <stdio.h>
#include <stdlib.h>



int getBitCount(int num)
{
    int bit_count = 0;
    while (num) {
        num /= 10;
        bit_count++;
    }
    return bit_count;
}


int main()
{
    int Bai, Shi, Ge;
    int i;
    int a;
    int bit_count;
    scanf("%d", &a);
    bit_count = getBitCount(a);

    switch(bit_count) {
        case 1:
            for (i = 0; i < a; i++) {
                printf("%d", i + 1);
            }
            break;
        case 2:
            Shi = a / 10 % 10;
            for (i = 0; i < Shi; i++) {
                printf("S");
            }
            Ge = a / 1 % 10;
            for (i = 0; i < Ge; i++) {
                printf("%d", i + 1);
            }
            break;

        case 3:
            Bai = a / 100 % 10;
            for (i = 0; i < Bai; i++) {
                printf("B");
            }
            Shi = a / 10 % 10;
            for (i = 0; i < Shi; i++) {
                printf("S");
            }
            Ge = a / 1 % 10;
            for (i = 0; i < Ge; i++) {
                printf("%d", i + 1);
            }
            break;

        default: break;
    }

    return 0;
}
