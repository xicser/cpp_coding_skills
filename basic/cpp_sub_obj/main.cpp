#include <iostream>

using namespace std;

class A
{
private:
    int x1;

public:
    A() {
        x1 = 0;
        cout << "A Constructor1" << endl;
    }
    A(int i) {
        x1 = i;
        cout << "A Constructor2" << endl;
    }

    void disp() {
        cout << "x1=" << x1 << endl;
    }
};

class B
{
private:
    int x2;

public:
    B() {
        x2 = 0;
        cout << "B Constructor1" << endl;
    }
    B(int i) {
        x2 = i;
        cout << "B Constructor2" << endl;
    }

    void disp() {
        cout << "x2=" << x2 << endl;
    }
};

class C: public A
{
private:
    int x3;
    B b1;

public:
    C() {
        x3 = 0;
        cout << "C Constructor1" << endl;
    }
    C(int x, int y, int z): A(x), b1(y) {
        x3 = z;
        cout << "C Constructor2" << endl;
    }

    void disp() {
        A::disp();
        b1.disp();
        cout << "x3=" << x3 << endl;
    }
};

int main()
{
    C c1;
    c1.disp();

    C c2(1, 2, 3);
    c2.disp();

    return 0;
}
