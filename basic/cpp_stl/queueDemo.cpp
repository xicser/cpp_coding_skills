/*
queue没有迭代器
使用front和pop之前, 必须用empty判断队列是否为空, 否则会出错
*/

#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

void queueDemo(void)
{
    printf("**************************queue test****************************\n");

    //定义
    queue<int> q;

    //push入队
    for (int i = 1; i <= 5; i++) {
        q.push(i);
    }

    //front, back
    printf("%d %d\n", q.front(), q.back());

    //pop出队
    q.pop();
    printf("%d\n", q.front());

    //empty
    printf("%d\n", q.empty());

    //size
    printf("%d\n", q.size());
}
