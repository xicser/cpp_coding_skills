#include <iostream>

using namespace std;

class A {
public:
    A() {
        cout << "A()" << endl;
    }
    A(int a) {
        cout << "A(int a)" << endl;
    }
    A(int a, int b = 6) {
        cout << "A(int a, int b)" << endl;
    }
};

void func(A a)
{

}

/*

分析方法：
先搞清调用形式, 然后找对应的构造函数

*/
int main()
{
    A a1;               //A()
//    A a2(2);          //A(2)

    A *a3 = new A;      //A()
    A *a4 = new A();    //A()

    func(A());          //A()

    return 0;
}
