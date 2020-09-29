#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, col;

    int a;
    char c;
    scanf("%d", &a);
    getchar();
    c = getchar();

    col = a;
    row = (a + 1) / 2;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {

            if (i == 0 || j == 0 || i == row - 1 || j == col - 1) {
                printf("%c", c);
            }
            else printf(" ");

        }
        printf("\n");
    }

    return 0;
}
