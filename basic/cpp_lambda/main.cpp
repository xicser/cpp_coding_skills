#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

/*
捕获形式                说明
[]               不捕获任何外部变量
[变量名, …]         默认以值得形式捕获指定的多个外部变量（用逗号分隔），如果引用捕获，需要显示声明（使用&说明符）
[this]           以值的形式捕获this指针
[=]              以值的形式捕获所有外部变量
[&]              以引用形式捕获所有外部变量
[=, &x]          变量x以引用形式捕获，其余变量以传值形式捕获
[&, x]           变量x以值的形式捕获，其余变量以引用形式捕获

Lambda表达式完整的声明格式如下：
[capture list] (params list) mutable exception-> return type { function body }
例子：
auto f = []() -> int {
    return 4;
};

[capture list] (params list) -> return type {function body}
[capture list] (params list) {function body}
[capture list] {function body}

在Lambda表达式中传递参数还有一些限制，主要有以下几点：
参数列表中不能有默认参数
不支持可变参数
所有参数必须有参数名

*/

void test1()
{
    vector<int> lbvec{ 3, 2, 5, 7, 3, 2 };

    sort(lbvec.begin(), lbvec.end(), [](int a, int b) -> bool { return a < b; });   // Lambda表达式
    cout << "lambda expression:" << endl;
    for (int it : lbvec)
        cout << it << ' ';
}

void test2()
{
    int a = 123;
    auto f = [a] { cout << a << endl; };
    f(); // 输出：123

    //或通过“函数体”后面的‘()’传入参数
    [](int a){cout << a << endl;}(123);
}

void test3()
{
    int a = 123;
    auto f = [a] { cout << a << endl; };
    a = 321;
    f(); // 输出：123
}

void test4()
{
    int a = 123;
    auto f = [&a] { cout << a << endl; };
    a = 321;
    f(); // 输出：321
}

void test5()
{
    int a = 123;
    auto f = [=] { cout << a << endl; };      // 值捕获
//    auto f = [=] { cout << a << endl; };    // 引用捕获
    f(); // 输出：123
}

void test6()
{
    int a = 123;
    auto f = [a]()mutable { cout << ++a << endl; }; // 不会报错, 不加mutable会报错
    cout << a << endl; // 输出：123
    f(); // 输出：124
    cout << a << endl; // 输出：123
}

void test7()
{
    int m = [](int x) {
        return [](int y) { return y * 2; }(x) + 6;
    }(5);
    std::cout << "m:" << m << std::endl;    //输出16

    std::cout << "n:" << [](int x, int y) { return x + y; }(5, 4) << std::endl;            //输出9

    auto gFunc = [](int x) -> function<int(int)> { return [=](int y) { return x + y; }; };
    auto lFunc = gFunc(4);
    std::cout << lFunc(5) << std::endl;

    auto hFunc = [](const function<int(int)>& f, int z) { return f(z) + 1; };
    cout << hFunc(gFunc(7), 8) << endl;
}

void test8()
{
    int a = 111, b = 222;
    auto func = [=, &b]()mutable { a = 22; b = 333; std::cout << "a:" << a << " b:" << b << std::endl; };
    func();
    std::cout << "a:" << a << " b:" << b << std::endl;

    a = 333;
    auto func2 = [=, &a] { a = 444; std::cout << "a:" << a << " b:" << b << std::endl; };
    func2();

    auto func3 = [](int x) -> function<int(int)> {
        return [=](int y) {
            return x + y;
        };
    };
    cout << func3(11)(15) << endl;

    std::function<void(int)> f_display_42 = [](int x) { cout << x << endl; };
    f_display_42(44);
}

int main()
{
//    test2();
//    test6();

//    test7();
    test8();

}
