#include <iostream>

using namespace std;


class Point
{
public:
    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }

    double x, y;
};

class Machine {

public:
    //基类当中声明一个纯虚函数, 表示抽象出来一个动作, 比如无人机和无人车都有的move
    virtual void move(Point p1, Point p2) {
        cout << "Machine move..." << endl;
    };

    //加virtual是防止内存泄漏, 继承时，要养成的一个好习惯就是，基类析构函数中，加上virtual
    virtual ~Machine() {
        cout << "~Machine" << endl;
    }
};


class UAV : public Machine {

public:
    //UAV特有的move
    virtual void move(Point p1, Point p2) {
        printf("UAV move from p1(%.2lf, %.2lf) to p2(%.2lf, %.2lf)\n", p1.x, p1.y, p2.x, p2.y);
    }

    ~UAV() {
        cout << "~UAV" << endl;
    }
};

class CAR : public Machine {

public:
    //CAR特有的move
    virtual void move(Point p1, Point p2) {
        printf("CAR move from p1(%.2lf, %.2lf) to p2(%.2lf, %.2lf)\n", p1.x, p1.y, p2.x, p2.y);
    }
    ~CAR() {
        cout << "~CAR" << endl;
    }

};

int main()
{
    UAV *uav = new UAV();
//    CAR *car = new CAR();

    //uav->move(Point(0, 0), Point(1, 1));
    //car->move(Point(0, 0), Point(1, 1));

    Machine *machine1 = uav;  //基类指针指向子类对象uav
//    machine1->move(Point(0.1, 0.2), Point(1.1, 1.2));  //多态, 调用的是uav对象里面的move

//    Machine *machine2 = car;  //基类指针指向子类对象car
//    machine2->move(Point(0.3, 0.4), Point(1.5, 1.6));  //多态, 调用的是car对象里面的move

    delete machine1;
//    delete machine2;

    return 0;
}
