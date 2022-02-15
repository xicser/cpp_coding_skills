/**
“隐藏”是指派生类的函数屏蔽了与其同名的基类函数，规则如下：
（1）如果派生类的函数与基类的函数同名，但是参数不同。此时，不论有无virtual关键字，基类的函数将被隐藏。
（2）如果派生类的函数与基类的函数同名，并且参数也相同，但是基类函数没有virtual关键字。此时，基类的函数被隐藏。
这种隐藏规则，不仅仅是表现在对成员函数上，对同名的data member也是如此。
*/

#include <iostream>
using namespace std;

class Base1
{
public:
    virtual void f(float x){ cout << "Base::f(float) " << x << endl; }
    virtual void g(float x){ cout << "Base::g(float) " << x << endl; }
    void h(float x){ cout << "Base::h(float) " << x << endl; }
};

class Derived1 : public Base1
{
public:
    virtual void f(float x){ cout << "Derived::f(float) " << x << endl; }
    virtual void g(int x){ cout << "Derived::g(int) " << x << endl; }
    void h(float x){ cout << "Derived::h(float) " << x << endl; }
};

int test2()
{
    Derived1  d;
    Base1 *pb = &d;
    Derived1 *pd = &d;

    // Good : behavior depends solely on type of the object
    pb->f(3.14f); // Derived::f(float) 3.14
    pd->f(3.14f); // Derived::f(float) 3.14

    // Bad : behavior depends on type of the pointer
    pb->g(3.14f); // Base::g(float) 3.14 (surprise!)
    pd->g(3.14f); // Derived::g(int) 3

    // Bad : behavior depends on type of the pointer
    pb->h(3.14f); // Base::h(float) 3.14  (surprise!)
    pd->h(3.14f); // Derived::h(float) 3.14

    return 0;
}

