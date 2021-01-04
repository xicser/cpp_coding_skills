#include <iostream>

using namespace std;

void test1(void)
{
    int x = 1, y = 0;
    try {
        if (y == 0) {
            throw (char *)"denominator is zero";
        } else {
            cout << "x / y" << x / y << endl;
        }
    } catch (const char *str) {
        cout << str << endl;
    }
}


void func1(int x)
{
    if (x <= 0) {
        throw x;
    } else {
        cout << x * 10 << endl;
    }
}
void test2(void)
{
    try {
        func1(5);
        func1(-6);
        func1(4);
    } catch (int m) {
        cout << m << " error" << endl;
    }
    cout << "end..." << endl;
}


void test3(int x)
{
    try {
        if (x == 0) {
            throw x;
        }
        if (x < 0) {
            throw "string exception !";
        }
        if (x > 0) {
            throw 1.23;
        }
    }
    catch (int n) {
        cout << n << endl;
    }
    catch (const char *str) {
        cout << str << endl;
    }
    catch(...) {
        cout << "call exception !" << endl;
    }
}



class A {
public:
    A() {
        cout << "A()" << endl;
    }

    A(const A &a) {
        cout << "A(A &a)" << endl;
    }

    ~A() {
        cout << "~A()" << endl;
    }

};

class B {
public:
    B() {
        cout << "B()" << endl;
    }

    ~B() {
        cout << "~B()" << endl;
    }

    void fun() {
        cout << "throw exception" << endl;
        throw A();
    }
};

void test4(void)
{
    B b;
    try {
        b.fun();
    } catch (A a) {
        cout << "test4" << endl;
    }
}

int main()
{
//    test1();
//    test2();

//    test3(4);
//    test3(0);
//    test3(4);

    test4();

    return 0;
}
