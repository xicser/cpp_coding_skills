#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getBitCount(int num)
{
    int bit_count = 0;
    while (num) {
        num /= 10;
        bit_count++;
    }
    return bit_count;
}
void print_hz(int num)
{
    switch (num) {
        case 0: printf("ling"); break;
        case 1: printf("yi"); break;
        case 2: printf("er"); break;
        case 3: printf("san"); break;
        case 4: printf("si"); break;
        case 5: printf("wu"); break;
        case 6: printf("liu"); break;
        case 7: printf("qi"); break;
        case 8: printf("ba"); break;
        case 9: printf("jiu"); break;
        default: break;
    }
}
int pow10(int num)
{
    int sum = 1;

    while (num) {
        num--;
        sum *= 10;
    }
    return sum;
}

int main()
{
    int i, k;
    int sum = 0;
    int bit_count;
    char str[1000];

    gets(str);

    for (i = 0; str[i] != 0; i++) {
        sum += str[i] - 48;
    }
    bit_count = getBitCount(sum);
    for (i = 0, k = pow10(bit_count - 1); i < bit_count; i++, k /= 10) {
        print_hz(sum / k % 10);
        if (i != bit_count - 1) {
            printf(" ");
        }
    }
    return 0;
}
