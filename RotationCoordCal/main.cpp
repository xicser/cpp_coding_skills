/*

计算坐标

*/

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;


//点定义
struct Point_t {
    double x, y;
    Point_t(double x, double y) {
        this->x = x;
        this->y = y;
    }
};

/* 计算平面内两点距离 */
double getDistance2D(Point_t p1, Point_t p2)
{
    double x1, y1, x2, y2;
    x1 = p1.x;
    y1 = p1.y;
    x2 = p2.x;
    y2 = p2.y;

    return sqrt( (x1 -  x2) * (x1 -  x2) + (y1 -  y2) * (y1 -  y2) );
}

//获取夹角
double getAngle(Point_t v)
{
    Point_t vh(1, 0);
    double product = (vh.x * v.x) + (vh.y * v.y);
    double moduleLengthV = getDistance2D(Point_t(0, 0), v);
    double moduleLengthVh = getDistance2D(Point_t(0, 0), vh);

    return acos(product / moduleLengthV / moduleLengthVh) * 180 / 3.141592653;
}

Point_t getCoord(Point_t center, Point_t p, double theta)
{
    double x, y;
    double thetaB = theta * (3.141592653 / 180);  //先转换成弧度

    x = (p.x - center.x) * cos(thetaB) - (center.y - p.y) * sin(thetaB) + center.x;
    y = (p.y - center.y) * cos(thetaB) + (center.x - p.x) * sin(thetaB) + center.y;

    return Point_t(x, y);
}


int main()
{
    Point_t p = getCoord(Point_t(1, 1), Point_t(2, 1), -45);
    cout << p.x  << p.y << endl;

    return 0;
}
