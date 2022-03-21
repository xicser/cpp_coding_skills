/*
vector就是一变长数组

3、 resize() 和 reserve()
resize()：改变当前容器内含有元素的数量(size())，?不是容器的容量
1. 当resize(len)中len>v.capacity()，则数组中的size和capacity（是这样吗？代码验证下来不是这样的）均设置为len;
2. 当resize(len)中len<=v.capacity()，则数组中的size设置为len，?capacity不变;

reserve()：改变当前容器的最?容量（capacity）
1. 如果reserve(len)的值 > 当前的capacity()，那么会重新分配?块能存len个对象的空间，然后把之前的对象通
过copy construtor复制过来，销毁之前的内存;
2. 当reserve(len)中len<=当前的capacity()，则数组中的capacity不变， size不变，即不对容器做任何改变。

*/

#include <iostream>
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

void resizeTest()
{
    vector<int> arr;
    for (int i = 1; i <= 10; i++) {
        arr.push_back(i);
    }
    printf("cap = %d\n", arr.capacity());
    printf("size = %d\n", arr.size());
    for (int i = 0; i < arr.size(); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("\n");

    arr.resize(15);

    printf("cap = %d\n", arr.capacity());
    printf("size = %d\n", arr.size());
    for (int i = 0; i < arr.size(); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

class testDemo
{
public:
    testDemo(int num) :num(num) {
        std::cout << "调用构造函数." << endl;
    }
    testDemo(const testDemo& other) :num(other.num) {
        std::cout << "调用拷贝构造函数." << endl;
    }
    testDemo(testDemo&& other) :num(other.num) {
        std::cout << "调用移动构造函数." << endl;
    }
private:
    int num;
};
void emplaceBackTest()
{
    cout << "emplace_back:" << endl;
    std::vector<testDemo> demo1;
    demo1.emplace_back(2);
    cout << "push_back:" << endl;
    std::vector<testDemo> demo2;
    demo2.push_back(2);
}

