#include <iostream>

using namespace std;


class A {
public:
    int x;

    A() {
        cout << "A()" << endl;
    }
    ~A() {
        cout << "~A()" << endl;
    }
};

class B {
public:
    int x;

    B() {
        cout << "B()" << endl;
    }
    ~B() {
        cout << "~B()" << endl;
    }
};

class C : virtual public A {
public:
    C() {
        cout << "C()" << endl;
    }
    ~C() {
        cout << "~C()" << endl;
    }
};

class D : virtual public A {
public:
    D() {
        cout << "D()" << endl;
    }
    ~D() {
        cout << "~D()" << endl;
    }
};

class E {
public:
    E() {
        cout << "E()" << endl;
    }
    ~E() {
        cout << "~E()" << endl;
    }
};


class F : public B, public C, public D {

private:
    E eVar;

public:
    F() {
        cout << "F()" << endl;
    }
    ~F() {
        cout << "~F()" << endl;
    }

    void display(void) {
//        cout << x << endl;
    }
};


int main()
{
    F f;
    cout << "stop" << endl;
    return 0;
}
