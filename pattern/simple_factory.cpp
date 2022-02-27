#include <iostream>
#include <string>

using namespace std;

class AbstractFruit {
public:
    virtual void showName() = 0;
};

class Apple : public AbstractFruit {
public:
    virtual void showName() {

    }


};

class Banana : public AbstractFruit {
public:
    virtual void showName() {

    }


};

class Pear : public AbstractFruit {
public:
    virtual void showName() {

    }


};

class FruitFactory {



};


int main()
{
    std::cout << "Hello World!\n";
}
