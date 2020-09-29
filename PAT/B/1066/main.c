#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x_res, y_res, SectionA, SectionB, Grayvalue;
    scanf("%d %d %d %d %d", &x_res, &y_res, &SectionA, &SectionB, &Grayvalue);
    int pic[x_res][y_res];
    for (int i = 0; i < x_res; i++) {
        for (int j = 0; j < y_res; j++) {
            scanf("%d", &pic[i][j]);
        }
    }

    for (int i = 0; i < x_res; i++) {
        for (int j = 0; j < y_res; j++) {

            if (SectionA <= pic[i][j] && pic[i][j] <= SectionB) printf("%03d", Grayvalue);
            else printf("%03d", pic[i][j]);

            if (j != y_res - 1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
