/**
重写是指派生类函数重写基类函数，是C++的多态的表现，特征是：
（1）不同的范围（分别位于派生类与基类）；
（2）函数名字相同；
（3）参数相同；
（4）基类函数必须有virtual关键字。

成员函数被重载的特征：
（1）相同的范围（在同一个类中）；
（2）函数名字相同；
（3）参数不同；
（4）virtual关键字可有可无。
*/

#include <iostream>

using namespace std;

class Base
{
public:
    void f(int x){ cout << "Base::f(int) " << x << endl; }
    void f(float x){ cout << "Base::f(float) " << x << endl; }
    virtual void g(void){ cout << "Base::g(void)" << endl;}
};

class Derived : public Base
{
public:
    virtual void g(void){ cout << "Derived::g(void)" << endl;}
};

int test1()
{
    Derived  d;
    Base *pb = &d;
    pb->f(42);        // Base::f(int) 42
    pb->f(3.14f);     // Base::f(float) 3.14
    pb->g();          // Derived::g(void)

    return 0;
}
