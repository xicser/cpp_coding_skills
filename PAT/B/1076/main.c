#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d", &N);
    getchar();

    for (int i = 0 ; i < N; i++) {
        char str_tmp[25];
        gets(str_tmp);
        for (int j = 0; str_tmp[j] != 0; j++) {
            if (str_tmp[j] == 'T') {
                switch (str_tmp[j - 2]) {
                  case 'A': printf("1"); break;
                  case 'B': printf("2"); break;
                  case 'C': printf("3"); break;
                  case 'D': printf("4"); break;
                  default: break;
                }
                break;
            }
        }
    }

    return 0;
}
