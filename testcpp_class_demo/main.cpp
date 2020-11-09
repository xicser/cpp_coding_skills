#include <iostream>

using namespace std;

class Base
{
public:
    Base();
    Base(int val);

    int get_val(void);
    void set_val(int val);

private:
    int m_num;
};
Base::Base() : m_num(1) {
    cout << "this is Base()" << endl;
}
Base::Base(int val) : m_num(val) {
    cout << "this is Base(int val)" << endl;
}

int Base::get_val(void) {
    return m_num;
}
void Base::set_val(int val) {
    m_num = val;
}




class BaseChild : public Base
{
public:
    BaseChild(int val = 9);

    int getval(void);
    void setval(int val);

private:
    int m_num;
};
BaseChild::BaseChild(int val) : Base(val), m_num(13) {
    cout << "this is BaseChild(val)" << endl;
}

int BaseChild::getval(void) {
    return m_num;
}
void BaseChild::setval(int val) {
    m_num = val;
}


class Test {
public:
    Test() {
        cout << "Test()" << endl;
    };
    Test(int a) {
        cout << "Test(int a)" << endl;
    };

};


void test(Test ts)
{
    cout << "test(Test ts)" << endl;
}
int main(int argc, char *argv[])
{
    BaseChild b;



    return 0;
}
