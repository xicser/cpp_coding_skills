/*
��������ģʽ = �򵥹���ģʽ + ������ԭ��
*/

#include <iostream>
#include <string>

using namespace std;

/* ˮ������ */
class AbstractFruit {
public:
    AbstractFruit() {

    }
    virtual ~AbstractFruit() {
        cout << "~AbstractFruit" << endl;
    }

    virtual void showName() = 0;
};

/* ƻ�� */
class Apple : public AbstractFruit {
public:
    Apple() {

    }
    ~Apple() {
        cout << "~Apple" << endl;
    }

    virtual void showName() {
        cout << "I'm Apple" << endl;
    }
};

/* �㽶 */
class Banana : public AbstractFruit {
public:
    Banana() {

    }
    ~Banana() {

    }

    virtual void showName() {
        cout << "Banana" << endl;
    }
};

/* �������� */
class AbstractFactory {
public:
    AbstractFactory() {

    }
    virtual ~AbstractFactory() {
        cout << "~AbstractFactory" << endl;
    }
    virtual AbstractFruit* createFruit() = 0;
};

/* ƻ������ */
class AppleFactory : public AbstractFactory {
public:
    AppleFactory() {

    }
    virtual ~AppleFactory() {
        cout << "~AppleFactory" << endl;
    }

    virtual AbstractFruit* createFruit() {
        return new Apple();
    }
};

/* �㽶���� */
class BananaFactory : public AbstractFactory {
public:
    BananaFactory() {

    }
    virtual ~BananaFactory() {
        cout << "~BananaFactory" << endl;
    }

    virtual AbstractFruit* createFruit() {
        return new Banana();
    }
};


int main()
{
    //��ƻ��Ϊ��
    AppleFactory appleFactory;  //ƻ������
    AbstractFruit* apple = appleFactory.createFruit(); //����ƻ��
    apple->showName();
    delete apple;

    return 0;
}
