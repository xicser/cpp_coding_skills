
/*

静态联编

*/

#include <iostream>

using namespace std;



class A {
public:
    void print() {
        cout << "This is A" << endl;
    }
};

class B : public A {
public:
    void print() {
        cout << "This is B" << endl;
    }
};

class C : public A {
public:
    void print() {
        cout << "This is C" << endl;
    }
};

void func1(A &s) {
    s.print();
}

void func2(A *s) {
    s->print();
}

int main()
{
    A a;
    B b;
    C c;

    a.print();
    b.print();
    c.print();

    func1(a);
    func1(b);
    func1(c);

    func2(&a);
    func2(&b);
    func2(&c);

    return 0;
}
