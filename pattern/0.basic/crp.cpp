
/*
合成复用原则
优先使用组合, 而不是继承
*/

#include <iostream>

using namespace std;

class AbstractCar {
public:
    virtual void run() = 0;
};


class Dazhong : public AbstractCar {
public:
    virtual void run() {
        cout << "Dazhong starting" << endl;
    }
};


class Tuolaji : public AbstractCar {
public:
    virtual void run() {
        cout << "Tuolaji starting" << endl;
    }
};


class Person {
private:
    AbstractCar* car;   //将car作为子对象, 而不是让Person继承大众，或者拖拉机

public:
    void setCar(AbstractCar* car) {
        this->car = car;
    }
    void douFeng() {
        car->run();
    }
};

void test3()
{
    Person person;
    Dazhong dazhong;
    Tuolaji tuolaji;

    person.setCar(&dazhong);
    person.douFeng();

    person.setCar(&tuolaji);
    person.douFeng();

}