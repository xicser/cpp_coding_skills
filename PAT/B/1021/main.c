#include <stdio.h>
#include <stdlib.h>


int N[10] = {0};
int main()
{
    char c;
    while (1) {
        scanf("%c", &c);
        if (c == '\n') break;

        N[c - 48]++;
    }

    for (int i = 0; i < 10; i++) {
        if (N[i]) {
            printf("%d:%d\n", i, N[i]);
        }
    }


    return 0;
}
