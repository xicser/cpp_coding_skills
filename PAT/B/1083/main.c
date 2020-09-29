#include <stdio.h>
#include <stdlib.h>


/*
8
3 5 8 6 2 1 4 7
1 2 3 4 5 6 7 8

2 3 5 2 3 5 3 1

5 2
3 3
2 2

*/
typedef struct {
    int rev_num;
    int minus;
} Card_t;

int main()
{
    int N;
    scanf("%d", &N);
    Card_t cards[N + 1];
    for (int i = 1; i <= N; i++) {
        scanf("%d", &cards[i].rev_num);
        cards[i].minus = abs(cards[i].rev_num - i);
    }

    int output[10005] = {0};
    int max_index = -1;
    for (int i = 1; i <= N; i++) {
        if (cards[i].minus > max_index) {
            max_index = cards[i].minus;
        }
        output[cards[i].minus]++;
    }

    for (int i = max_index; i >= 0; i--) {
        if (output[i] >= 2) {
            printf("%d %d\n", i, output[i]);
        }
    }

    return 0;
}
