#include <stdio.h>
#include <stdlib.h>


void cal_A1(int *array, int len)
{
    int cnt = 0;
    int sum = 0;
    int i;
    for (i = 0; i < len; i++) {
        if (array[i] % 5 == 0 && array[i] % 2 == 0) {
            sum += array[i];
            cnt++;
        }
    }
    if (cnt != 0) {
        printf("%d ", sum);
    } else printf("N ");
}
void cal_A2(int *array, int len)
{
    int i;
    int cnt = 0;
    int k = 1;
    int sum = 0;

    for (i = 0; i < len; i++) {
        if (array[i] % 5 == 1) {
            sum += array[i] * k;
            k *= -1;
            cnt++;
        }
    }
    if (cnt != 0) {
        printf("%d ", sum);
    } else printf("N ");
}
void cal_A3(int *array, int len)
{
    int cnt = 0;
    int i;
    for (i = 0; i < len; i++) {
        if (array[i] % 5 == 2) {
            cnt++;
        }
    }
    if (cnt != 0) {
        printf("%d ", cnt);
    } else printf("N ");
}
void cal_A4(int *array, int len)
{
    int i;
    int cnt = 0;
    double sum = 0;
    for (i = 0; i < len; i++) {
        if (array[i] % 5 == 3) {
            sum += array[i];
            cnt++;
        }
    }
    if (cnt != 0) {
        printf("%.1lf ", sum / cnt);
    } else printf("N ");
}
void cal_A5(int *array, int len)
{
    int i;
    int max;
    int cnt = 0;

    for (i = 0; i < len; i++) {
        if (array[i] % 5 == 4) {
            max = array[i];
            break;
        }
    }

    for (i = 0; i < len; i++) {
        if (array[i] % 5 == 4) {
            cnt++;
            if (max < array[i]) {
                max = array[i];
            }
        }
    }
    if (cnt != 0) {
        printf("%d", max);
    } else printf("N");
}

int main()
{
    int i;
    int N;
    scanf("%d", &N);
    int array[N];

    for (i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    cal_A1(array, N);
    cal_A2(array, N);
    cal_A3(array, N);
    cal_A4(array, N);
    cal_A5(array, N);

    return 0;
}
