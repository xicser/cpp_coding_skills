#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

void lower_upper_bound(void);
void algorithmDemo(void)
{
    printf("**************************algorithm test****************************\n");

    //max, min, abs
    int x = 1, y = -2;
    printf("%d %d\n", max(x, y), min(x, y));
    printf("%d %d\n", abs(x), abs(y));

    //swap
    printf("%d %d\n", x, y);
    swap(x, y);
    printf("%d %d\n", x, y);

    //reverse
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (unsigned int i = 0; i < sizeof(a) / sizeof(int); i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    reverse(a, a + sizeof(a) / sizeof(int));
    for (unsigned int i = 0; i < sizeof(a) / sizeof(int); i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    //next_permutation
    int b[] = {1, 2, 3};
    do {
        printf("%d %d %d\n", b[0], b[1], b[2]);
    } while (next_permutation(b, b + 3));

    //fill
    fill(b, b + 3, 8);
    for (int i = 0; i < 3; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

    //sort
    int c[] = {2, 4, 23, 1, 7, 87, 15};
    sort(c, c + sizeof(c)/ sizeof(int), [=](int a, int b) { //lamda表达式
         return a > b;
    });
    for (unsigned int i = 0; i < sizeof(c)/ sizeof(int); i++) {
        printf("%d ", c[i]);
    }
    printf("\n");

    //lower_bound, upper_bound
    lower_upper_bound();
}

void lower_upper_bound(void)
{
    int a[10] = {1, 2, 2, 3, 3, 3, 5, 5, 5, 5};
    printf("%d %d\n", lower_bound(a, a + 10, 3) - a, upper_bound(a, a + 10, 3) - a);
    printf("%d\n", lower_bound(a, a + 10, 4) - a);
}
