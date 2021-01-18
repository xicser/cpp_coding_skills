#include <iostream>

using namespace std;

#define PI (3.141592653)

class Circle {
protected:
    double r;

public:
    Circle() {}
    Circle(double rr) {
        r = rr;
    }
    virtual double area() {
        return PI * r *r;
    }

    virtual void display() {
        cout << "circle radius = " << r << endl;
    }
};

class Globe : public Circle {
public:
    Globe(double rr) : Circle(rr) {

    }

    double area() {
        return 4 * PI * r * r;
    }

    void display() {
        cout << "globe radius = " << r << endl;
    }
};


class Cylinder : public Circle {
protected:
    double h;

public:
    Cylinder() {}
    Cylinder(double rr, double hh) : Circle(rr) {
        h = hh;
    }

    double area() {
        return 2 * PI * r * r + 2 * PI * r * h;
    }
    void display() {
        cout << "cylinder radius = " << r << "cylinder height = " << h << endl;
    }
};

void func1(Circle &c) {
    c.display();
}


void func1(Circle *c) {
    c->display();
}

int main()
{
    Circle cir(2);
    Globe glo(3);
    Cylinder cyl(4, 2);

    cir.display();
    glo.display();
    cyl.display();

    func1(cir);
    func1(glo);
    func1(cyl);

    func1(&cir);
    func1(&glo);
    func1(&cyl);

    return 0;
}
