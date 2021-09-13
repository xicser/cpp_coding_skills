#include <iostream>
#include <queue>
#include <stdio.h>
#include "prior_queueDemo.h"

using namespace std;

bool operator< (fruit f1, fruit f2)
{
    return f1.price < f2.price;
}

void prior_queueDemo(void)
{
    printf("**************************prior_queue test****************************\n");

    //定义
    priority_queue<int> q;

    //push
    q.push(3);
    q.push(4);
    q.push(1);

    //top获取堆顶元素
    printf("%d\n", q.top());

    //pop获取堆顶元素
    q.pop();
    printf("%d\n", q.top());

    //empty
    printf("%d\n", q.empty());

    //size
    printf("%d\n", q.size());

    //优先队列优先级设置
    //(1)基本数据类型
    priority_queue< int, vector<int>, greater<int> > q1; //最小的元素放在队首
    q1.push(3);
    q1.push(4);
    q1.push(1);
    printf("%d\n", q1.top());

    //(2)结构体(类)
    priority_queue<fruit> q2;
    fruit f1, f2, f3;
    f1.name = "peach";
    f1.price = 3;
    f2.name = "pear";
    f2.price = 4;
    f3.name = "apple";
    f3.price = 1;
    q2.push(f1);
    q2.push(f2);
    q2.push(f3);
    cout << q2.top().name << " " << q2.top().price << endl;
}
