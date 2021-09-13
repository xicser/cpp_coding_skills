#include <iostream>

using namespace std;

template <typename T>  //指出在类模板中用到的通用数据类型
class Point {
private:
    T x, y;
public:
    Point(T x, T y) {
        this->x = x;
        this->y = y;
    }

    T getX(void) {
        return x;
    }

    T getY(void) {
        return y;
    }

    void display();
};

template<typename T>      //成员函数的声明
void Point<T>::display()
{
    cout << x << " " << y << endl;
}

class A {
private:
    int a;
public:
    A(){}
    A(int x) {
        a = x;
    }
    A(A *p) {
        this->a = p->a;
    }

    void operator!(void) {
        cout << "a = " << a << endl;
    }
};

template<class T>
class B
{
private:
    int b;
    T *x;
public:
    B(int y, T *p) {
        b = y;
        x = new T(p);
    }
    void operator!(void)
    {
        cout << "b=" << b << endl;
        !*x;
    }
};

void testClassTemplate(void)
{
    Point<int> p0(3, 5);
    p0.display();

    Point<float> p1(100, 200.5);
    p1.display();

    A a(1);
    B<A> b(2, &a);
    !b;
}
