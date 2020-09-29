#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>


using namespace std;

int main()
{
    int arr[10];

    fill(arr, arr + 10, 2);
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    fill(arr, arr + 10, -3);
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    fill(arr, arr + 10, 9);
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
