/*
简单工厂模式
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
        cout << "Apple" << endl;
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

/* 梨子 */
class Pear : public AbstractFruit {
public:
    Pear() {

    }
    ~Pear() {

    }

    virtual void showName() {
        cout << "Pear" << endl;
    }
};


/* 水果工厂 */
class FruitFactory {
public:
    static AbstractFruit* createFruit(const string& name) {
        if (name == "Apple") {
            return new Apple();
        }
        else if (name == "Banana") {
            return new Banana();
        }
        else if (name == "Pear") {
            return new Pear();
        }
        else {
            return nullptr;
        }
    }
};

int main()
{
    FruitFactory fruitFactory;
    AbstractFruit* apple = fruitFactory.createFruit("Apple");
    apple->showName();
    delete apple;

    return 0;
}
