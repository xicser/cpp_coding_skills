#include<iostream>
using namespace std;

class A {

public:
    int v;

    A()
    {
        cout << "A()" << endl;
    }

    //构造函数
    A(int i)
    {
        v = i;
        cout << "Constuctor" << v << endl;
    };

    //复制构造函数
    A(const A &a)
    {
        this->v = a.v;
        cout << "Copy constructer called" << this->v << endl;
    }
};

A Func(A a1)//普通函数
{
    a1.v++;
    return a1;
}

int main()
{
    A a(5);
    A b = a;
    A c = Func(a);

    cout << b.v << endl;
    cout << c.v << endl;

    A d;
    Func(a);
    d = Func(a);
    cout << d.v << endl;

    return 0;
}
