#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    int line;
    char c;

    scanf("%d", &N);
    getchar();
    scanf("%c", &c);


    //找行数先
    for (line = 1; ; line += 2) {
        int count = (line + 3) * (line / 2) + 1;
        if (count == N)  {
            break;
        } else if (count > N) {
            line = line - 2;
            break;
        }
    }
//    printf("line = %d\n", line);

    int used = (line + 3) * (line / 2) + 1;

    //打印沙漏
    for (int i = 0; i < line / 2 + 1; i++) {
        for (int j = 0; j < line; j++) {
            if (j >= i && j + i < line) {
                printf("%c", c);
            } else if (i > j) {
                printf(" ");
            }
        }
        printf("\n");
    }
    //打印剩下的
    for (int i = line / 2 + 1; i < line; i++) {
        for (int j = 0; j < line; j++) {
            if (i >= j && j + i >= line - 1) {
                printf("%c", c);
            } else if (j < i) {
                printf(" ");
            }
        }
      //  if (i != line - 1)
        printf("\n");
    }

    printf("%d", N - used);

    return 0;
}

/*

19 *
*****
 ***
  *
 ***
*****
*/
