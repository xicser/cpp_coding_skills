/* 普通函数作为友元函数 */
#include <iostream>
#include <math.h>
#include "Normal.h"

using namespace std;

/* 点 */
Point::Point()
{
    cout << "Point()" << endl;
}

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
    cout << "Point(double x, double y)" << endl;
}


/* 直线 */
Line::Line()
{
    cout << "Line()" << endl;
}
Line::Line(double a, double b, double c)
{
    this->a = a;
    this->b = b;
    this->c = c;
    cout << "Line(double a, double b, double c)" << endl;
};

/* 计算点到直线距离 */
double dist(Point p, Line l)
{
    //友元函数中可以直接访问类的私有成员
    return p.x + l.a;
}
