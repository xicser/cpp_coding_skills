#include <stdio.h>
#include <stdlib.h>

unsigned char point_times[16777222] = {0};

typedef struct {
    int x, y;
    int color;
} Point_t;

int My_abs(int a, int b)
{
    return abs(a - b);
}
int main()
{
    int M, N, TOL;

    scanf("%d%d%d", &M, &N, &TOL);
    int array[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    Point_t points[N * M];
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int tmp = array[i][j];

            if (i == 0 && j != 0 && j != M - 1) { //上面一行
                if (My_abs(tmp, array[i][j - 1]) > TOL &&
                    My_abs(tmp, array[i][j + 1]) > TOL &&
                    My_abs(tmp, array[i + 1][j - 1]) > TOL &&
                    My_abs(tmp, array[i + 1][j]) > TOL &&
                    My_abs(tmp, array[i + 1][j + 1]) > TOL
                    ) {
                    points[count].color = tmp;
                    points[count].x = j + 1;
                    points[count].y = i + 1;
                    count++;
                    point_times[tmp]++;
                }
            } else if (i == N - 1 && j != 0 && j != M - 1) { //下面一行
                if (My_abs(tmp, array[i][j - 1]) > TOL &&
                    My_abs(tmp, array[i][j + 1]) > TOL &&
                    My_abs(tmp, array[i - 1][j - 1]) > TOL &&
                    My_abs(tmp, array[i - 1][j]) > TOL &&
                    My_abs(tmp, array[i - 1][j + 1]) > TOL
                    ) {
                    points[count].color = tmp;
                    points[count].x = j + 1;
                    points[count].y = i + 1;
                    count++;
                    point_times[tmp]++;
                }
            } else if (j == 0 && i != 0 && i != N - 1) { //左边一列
                if (My_abs(tmp, array[i - 1][j]) > TOL &&
                    My_abs(tmp, array[i + 1][j]) > TOL &&
                    My_abs(tmp, array[i - 1][j + 1]) > TOL &&
                    My_abs(tmp, array[i][j + 1]) > TOL &&
                    My_abs(tmp, array[i + 1][j + 1]) > TOL
                    ) {
                        points[count].color = tmp;
                        points[count].x = j + 1;
                        points[count].y = i + 1;
                        count++;
                        point_times[tmp]++;
                    }
            } else if (j == M - 1 && i != 0 && i != N - 1) {  //右边一列
                if (My_abs(tmp, array[i - 1][j]) > TOL &&
                    My_abs(tmp, array[i + 1][j]) > TOL &&
                    My_abs(tmp, array[i - 1][j - 1]) > TOL &&
                    My_abs(tmp, array[i][j - 1]) > TOL &&
                    My_abs(tmp, array[i + 1][j - 1]) > TOL
                    ) {
                        points[count].color = tmp;
                        points[count].x = j + 1;
                        points[count].y = i + 1;
                        count++;
                        point_times[tmp]++;
                    }
            }
            else { //中间的点
                if (My_abs(tmp, array[i - 1][j - 1]) > TOL &&
                    My_abs(tmp, array[i - 1][j]) > TOL &&
                    My_abs(tmp, array[i - 1][j + 1]) > TOL &&
                    My_abs(tmp, array[i][j - 1]) > TOL &&
                    My_abs(tmp, array[i][j + 1]) > TOL &&
                    My_abs(tmp, array[i + 1][j - 1]) > TOL &&
                    My_abs(tmp, array[i + 1][j]) > TOL &&
                    My_abs(tmp, array[i + 1][j + 1]) > TOL)
                {
                    points[count].color = tmp;
                    points[count].x = j + 1;
                    points[count].y = i + 1;
                    count++;
                    point_times[tmp]++;
                }
            }

        }
    }

    if (count > 1) {

        int i;
        for (i = 0; i < 16777222; i++) {
            if (point_times[i] == 1) {
                for (int j = 0; j < count; j++) {
                    if (i == points[j].color) {
                        printf("(%d, %d): %d\n", points[j].x, points[j].y, points[j].color);
                    }
                }
                break;
            }
        }
        if (i == 16777222) {
            printf("Not Unique\n");
        }
    } else if (count == 0) {
        printf("Not Exist\n");
    } else {
        printf("(%d, %d): %d\n", points[0].x, points[0].y, points[0].color);
    }

    return 0;
}
