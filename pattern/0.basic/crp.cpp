
/*
�ϳɸ���ԭ��
����ʹ�����, �����Ǽ̳�
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
    AbstractCar* car;   //��car��Ϊ�Ӷ���, ��������Person�̳д��ڣ�����������

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