/**
�����ء���ָ������ĺ�������������ͬ���Ļ��ຯ�����������£�
��1�����������ĺ��������ĺ���ͬ�������ǲ�����ͬ����ʱ����������virtual�ؼ��֣�����ĺ����������ء�
��2�����������ĺ��������ĺ���ͬ�������Ҳ���Ҳ��ͬ�����ǻ��ຯ��û��virtual�ؼ��֡���ʱ������ĺ��������ء�
�������ع��򣬲������Ǳ����ڶԳ�Ա�����ϣ���ͬ����data memberҲ����ˡ�
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

