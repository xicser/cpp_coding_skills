/*
vector就是一变长数组
*/

#include <vector>
#include <stdio.h>

using namespace std;

void vectorDemo(void)
{
    printf("**************************vector test****************************\n");

    //定义
    vector<int> name1;
    vector< vector<int> > name2;
    vector<int> Arrayname[100];

    //push_back在末尾添加元素
    for (int i = 0; i < 5; i++) {
        name1.push_back(i);
    }

    //元素访问
    vector<int>::iterator it;
    it = name1.begin();
    for (int i = 0; i < 5; i++) {
        printf("%d ", name1[i]);         //1通过下标[]访问, 和数组一样
        printf("%d\n", *(it + i));       //2通过迭代器访问
    }
    printf("\n"); //name1.end()是尾元素的下一个地址
    for (vector<int>::iterator it = name1.begin(); it != name1.end(); it++) {
        printf("%d", *it);
    }

    //pop_back删除尾部元素
    name1.pop_back();
    printf("\n"); //name1.end()是尾元素的下一个地址
    for (vector<int>::iterator it = name1.begin(); it != name1.end(); it++) {
        printf("%d", *it);
    }
    printf("\n");

    //size()获取元素个数
    printf("%d\n", name1.size());

    //clear()清空vector
    name1.clear();
    printf("%d\n", name1.size());

    //insert插入元素
    name1.push_back(4);
    name1.push_back(5);
    name1.push_back(6);
    name1.insert(name1.begin() + 1, -9999);
    name1.insert(name1.begin() + 1, -8888);
    for (vector<int>::iterator it = name1.begin(); it != name1.end(); it++) {
        printf("%d ", *it);
    }
    printf("\n");

    //erase删除元素, 注意区间是 左闭右开
    name1.erase(name1.begin(), name1.begin() + 2);  //删除name1[0], name1[1]
    for (vector<int>::iterator it = name1.begin(); it != name1.end(); it++) {
        printf("%d ", *it);
    }
    printf("\n");
    name1.erase(name1.begin());   //删除name1[0]
    for (vector<int>::iterator it = name1.begin(); it != name1.end(); it++) {
        printf("%d ", *it);
    }
    printf("\n");
}
