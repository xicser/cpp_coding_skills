#include <iostream>

using namespace std;

class A {

};

class B
{
public:
    B() {}
    ~B() {}
};

class C
{
public:
    C() {}
    virtual ~C() {}
};

class D {
    char ch;
    void func() { }
};

class E {
    char ch1; //占用1字节
    char ch2; //占用1字节
    virtual void func() { }
};

class F {
    int in;
    virtual void func() { }
};

class G :public A, public C {};
class H :public A, public B, public C {};
class I :public A, public C, public B {};

class AA {


};

class BB : public AA, public C {


};

int main()
{
    cout << "空类的大小：" << sizeof(A) << endl;                      //1
    cout << "带构造函数和析构函数的类的大小：" << sizeof(B) << endl;     //1
    cout << "带虚函数的类的大小：" << sizeof(C) << endl;               //4

    cout << "D类的大小" << sizeof(D) << endl;       //1
    cout << "E类的大小" << sizeof(E) << endl;       //8
    cout << "F类的大小" << sizeof(F) << endl;       //8

    cout << "G的大小" << sizeof(G) << endl;        //4
    cout << "H的大小" << sizeof(H) << endl;        //8
    cout << "I的大小" << sizeof(I) << endl;        //8


    cout << sizeof(BB) << endl;

    return 0;
}