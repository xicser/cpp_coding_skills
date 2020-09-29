#include <stdio.h>
#include <stdlib.h>



int bit_count(int a)
{
    int count = 0;

    while (a) {
        a /= 10;
        count++;
    }

    return count;
}

int output[50];
int out_index = 0;
int main()
{
    int A, B, product, bits;

    scanf("%d%d", &A, &B);
    product = A * B;

    bits = bit_count(product);


    for (int i = 0, k = 1; i < bits; i++, k *= 10) {
        int tmp = product / k % 10;
        output[out_index++] = tmp;
    }



    for (int i = 0; i < out_index; i++) {
        if (output[i]) {
            for (int j = i; j < out_index; j++) {
                printf("%d", output[j]);
            }
            break;
        }
    }


    return 0;
}
