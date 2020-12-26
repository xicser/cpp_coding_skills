#include <iostream>

using namespace std;



class Base {
public:
    Base() {
    }
    static int cnt;

    static int getCnt(void) {
        return cnt;
    }
};
int Base::cnt = 9;


class ClassA : public Base
{
public:
    ClassA() {

    }
};



int main()
{
    cout << Base::getCnt() << endl;
    cout << ClassA::getCnt() << endl;

    ClassA *classA = new ClassA;
    classA.getCnt();

    return 0;
}
