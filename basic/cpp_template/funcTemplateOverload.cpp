#include <iostream>

using namespace std;

template<typename T>
T Max(T x, T y)
{
    cout << "T Max(T x, T y)" << endl;
    return (x > y) ? x : y;
}

template <typename T>
T Max(T a, T b, T c)        //重载函数模板
{
    T s;
    cout << "T Max(T a, T b, T c)" << endl;
    s = Max(a, b);
    return Max(s, c);
}

int Max(int x, int y)       //用普通函数重载函数模板
{
    cout << "int Max(int x, int y)" << endl;
    return x > y ? x : y;
}

int Max(int x, char y)      //用普通函数重载函数模板
{
    cout << "int Max(int x, char y)" << endl;
    return x > y ? x : y;
}

void testFuncTemplateOverload(void)
{
    int i = 10;
    char c = 'a';
    double f = 98.74;

    Max(i, i);
    Max(c, c);
    Max(3.3, 5.6, 6.6);

    Max(i, c);
    Max(c, i);
    Max(f, f);

    Max(f, i);
//    Max(i, f);
}
