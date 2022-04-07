#include <iostream>

using namespace std;

// 重载被调用函数, 查看完美转发的效果
void otherdef(int& t)
{
    cout << "lvalue\n";
}
void otherdef(const int& t)
{
    cout << "rvalue\n";
}

// 实现完美转发的函数模板
template <typename T>
void func(T&& t)
{
    otherdef(forward<T>(t)); //完美转发
}

void test_forward()
{
    func(5);
    int x = 1;
    func(x);
}

//程序执行结果为：

//rvalue
//lvalue
