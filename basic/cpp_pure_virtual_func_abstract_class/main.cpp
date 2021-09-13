#include <iostream>

using namespace std;

const double PI = 3.1415926;

class Shape {
public:
    virtual double area() = 0;
    virtual void shapeName() = 0;
};


class Circle : public Shape {
private:
    double r;

public:
    Circle() {}
    Circle(double  rr) {r = rr;}
    virtual double area() {
        return PI * r * r;
    }
    virtual void shapeName() {
        cout << "Circle" << endl;
    }
};

class Rectangle : public Shape {
private:
    double x, y;

public:
    Rectangle() {}
    Rectangle(double xx, double yy) {
        x = xx;
        y = yy;
    }

    virtual double area() {
        return x * y;
    }
    virtual void shapeName() {
        cout << "Rectangle" << endl;
    }
};

class Ellipse : public Shape {
private:
    double rx, ry;

public:
    Ellipse() {}
    Ellipse(double rx, double ry) {
        this->rx = rx;
        this->ry = ry;
    }

    double area() { //只实现了area, 仍然是个抽象类, 故无法用来实例化对象
        return 4 * PI * rx * ry;
    }
};

int main()
{
    Shape *p;
    Circle c(2);
    Rectangle r(3, 4);

    p = &c;
    p->shapeName();
    cout << p->area() << endl;

    p = &r;
    p->shapeName();
    cout <<  p->area() << endl;

//    Ellipse ellipse; //报错


    return 0;
}
