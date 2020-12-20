#ifndef __NORMAL__
#define __NORMAL__

/* 点 */
class Line;
class Point {
private:
    double x, y;

public:
    Point();
    Point(double x, double y);

    //把这个普通函数作为Point类的友元函数
    friend double dist(Point p, Line l);
};

/* 直线 */
class Line {

private:
    double a, b, c;

public:
    Line();
    Line(double a, double b, double c);

    //把这个普通函数作为Line类的友元函数
    friend double dist(Point p, Line l);
};

double dist(Point p, Line l);

#endif // __NORMAL__
