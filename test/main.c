#include <stdio.h>
#include <stdlib.h>


//0 1 2 3 4
void BubbleSort(int *array, int n)
{
    int i, j;
    int tmp;
    for (i = 1; i <= n - 1; i++) { //共进行n - 1趟

        for (j = 0; j < n - i; j++) {
            if (array[j] > array[j + 1]) {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}
// 2 1 5 6 2
// 0 1 2 3 4
//n = 5
void selectSort(int *array, int n)
{
    int i, j, min;
    int tmp;

    //总共要经过n - 1轮比较
    for (i = 0; i < n - 1; i++) {
        min = i;

        // 每轮需要比较的次数 N-i
        for (j = i + 1; j < n; j++) {
            if (array[j] < array[min]) {
                // 记录目前能找到的最小值元素的下标
                min = j;
            }
        }

        // 将找到的最小值和i位置所在的值进行交换
        if (i != min) {
            tmp = array[i];
            array[i] = array[min];
            array[min] = tmp;
        }
    }
}

static int compare( const void *arg1, const void *arg2 )
{
    int *a = (int *) arg1;
    int *b = (int *) arg2;
    if (*a > *b) return 1;
    else return -1;
}

int Fib(int n)
{
    if (n == 1) return 1;
    if (n == 2) return 1;

    return Fib(n - 1) + Fib(n- 2);
}


int main()
{
//    int array[10];
//
//    for (int i = 9; i >= 0; i--) {
//        array[i] = i;
//        printf("%d ", array[i]);
//    }
//    printf("\n");
//
//    qsort(array, 10, 4, compare);
//
//    for (int i = 0; i < 10; i++) {
//        printf("%d ", array[i]);
//    }

    printf("%d", Fib(3));

    return 0;
}
