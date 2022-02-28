/*
工厂方法模式 = 简单工厂模式 + “开闭原则”
*/

#include <iostream>
#include <string>

using namespace std;

/* 水果抽象 */
class AbstractFruit {
public:
    AbstractFruit() {

    }
    virtual ~AbstractFruit() {
        cout << "~AbstractFruit" << endl;
    }

    virtual void showName() = 0;
};

/* 苹果 */
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

/* 香蕉 */
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

/* 工厂抽象 */
class AbstractFactory {
public:
    AbstractFactory() {

    }
    virtual ~AbstractFactory() {
        cout << "~AbstractFactory" << endl;
    }
    virtual AbstractFruit* createFruit() = 0;
};

/* 苹果工厂 */
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

/* 香蕉工厂 */
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
    //以苹果为例
    AppleFactory appleFactory;  //苹果工厂
    AbstractFruit* apple = appleFactory.createFruit(); //生产苹果
    apple->showName();
    delete apple;

    return 0;
}
