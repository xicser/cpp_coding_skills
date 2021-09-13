/*

演示C++中的sort函数使用方法

*/

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

struct node {
    int x, y;
} ssd[10];

bool cmp_strcut(node a, node b)
{
    if (a.x != b.x) return a.x > b.x; //对结构体进行二级排序
    else return a.y < b.y;
}

bool cmp(int a, int b)
{
    return a < b;
}
int main()
{
    int Array[6] = {9, 4, 2, 5, 6, -1};
    char Chars[] = {'T', 'W', 'A', 'K'};

//    //将A[0] -> A[3]从小到大排序
//    sort(Array, Array + 4);
//    for (int i = 0; i < 4; i++) {
//        printf("%d ", Array[i]);
//    }
//    printf("\n");

    //将Chars[0] -> Chars[3]从小到大排序
    sort(Chars, Chars + 4);
    for (int i = 0; i < 4; i++) {
        printf("%c ", Chars[i]);
    }
    printf("\n");


    //cmp函数实例
    sort(Array, Array + 6, cmp);
    for (int i = 0; i < 6; i++) {
        printf("%d ", Array[i]);
    }
    printf("\n");


    return 0;
}
