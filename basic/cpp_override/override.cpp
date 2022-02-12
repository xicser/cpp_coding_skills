#include <iostream>

using namespace std;

class Base {
private:
    int a;
    virtual int getValue() {
        return a;
    }
public:
    Base(int a) {
        this->a = a;
    }

};

class Son : public Base {
private:
    int a;


public:
    int getValue() {
        return a + 1;
    }    
    Son(int a) : Base(2) {
        this->a = a;
    }
};


int main()
{
    Son son(12);

 //   cout << son.getValue() << endl;
}
