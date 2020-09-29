#include <stdio.h>
#include <stdlib.h>


//逆序
static void reverseArr(int *arr, int start, int end)
{
    while(start <= end) {
        int tmp = arr[start];
        arr[start++] = arr[end];
        arr[end--] = tmp;
    }
}
//从后向前遍历找出arr[i] > arr[i-1]的下标i
static int returnIndex(int *arr, int arr_len){
    for (int i = arr_len - 1; i > 0; i--) {
        if(arr[i] > arr[i-1]) {
            return i;
        }
    }
    return 0;
}

//找到下一个排列
int findNearestNumber(int *arr_in, int arr_in_len)
{
    int index = returnIndex(arr_in, arr_in_len);
    if(index == 0) return 0; //没找到, 已经是最后一个了

    for(int i = arr_in_len - 1; i >= index; i--) {

        if(arr_in[index - 1] < arr_in[i]) {

            int tmp = arr_in[index - 1]; //交换
            arr_in[index - 1] = arr_in[i];
            arr_in[i] = tmp;
            break;
        }
    }

    reverseArr(arr_in, index, arr_in_len - 1);

    return 1;
}


static void allPermutation(int *a, int cursor, int k);
static void swap(int *a, int cursor, int i);
int main()
{
//    int arr_in[] = {5, 4, 3, 2, 1};
//
//    findNearestNumber(arr_in, 5);
//    for (int i = 0; i < 5; i++) {
//        printf("%d ", arr_in[i]);
//    }

    int a[] = {1, 5, 3, 4};
    allPermutation(a, 0, 4 - 1);

    return 0;
}

static void allPermutation(int *a, int cursor, int k)
{
    if (cursor == k) {
        for (int i = 0; i < 4; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }

    for (int i = cursor; i <= k; i++) {

        swap(a, cursor, i);

        allPermutation(a, cursor + 1, k);

        // 保证交换之前的序列还是 {1, 2, 3, 4}
        swap(a, cursor, i);
    }
}

static void swap(int *a, int cursor, int i)
{
    int temp = a[cursor];
    a[cursor] = a[i];
    a[i] = temp;
}




















