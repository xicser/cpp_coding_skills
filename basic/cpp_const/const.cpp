#include <iostream>
#include <stdio.h>

using namespace std;

class ClassA {

};

void test1(void);
void test2(void);
void test3(void);
void test4(const int * const p);
int * const test5(void);
const int *test6(void);
const ClassA test7(void);
const ClassA &test8(void);

int main(void)
{
    int a = 0;

    test1();
    test2();
    test3();
    test4(&a);
    int *p = test5();
    cout << *p << endl;
    const int *q = test6();
    cout << *q << endl;

    int * const r = &a; //定义的时候，必须初始化
//    r = 0;   //报错

    ClassA b = test7(); //返回的常对象

    const ClassA &c = test8();

    return 0;
}

void test1(void)
{
    int a = 10;
    const int *p = &a; //不可以用*p改变a的值
}

void test2(void)
{
    int a = 90;
    int * const p = &a; //指针变量p的值不可以修改
}

void test3(void)
{
    int a = 80;
    const int* const p = &a; //不可以用*p改变a的值, 同时指针变量p的值也不可以修改
}

void test4(const int * const p)
{
    //*p = 8;
}

int a = 999;
int * const test5(void)
{
    return &a;
}

const int *test6(void)
{
    return &a;
}

const ClassA test7(void)
{
    ClassA a;
    return a;
}

const ClassA &test8(void)
{
    ClassA a;
    return a;
}
