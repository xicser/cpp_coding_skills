#include <iostream>

using namespace std;

class Out {
public:
    Out() {
        cout << "Out" << endl;
    }
    ~Out() {
        cout << "~Out" << endl;
    }

    /*
    1, 和成员函数或者成员变量一样, 这个类也有访问权限（在这里是public）
    2, 可以把In这个类想象成一个普通的类, 只不过它的定义是在Out当中

    虽然嵌套类在外围类内部定义，但它是一个独立的类，基本上与外围类不相关。

    它的成员不属于外围类，同样，外围类的成员也不属于该嵌套类。
    嵌套类的出现只是告诉外围类有一个这样的类型成员供外围类使用。
    并且，外围类对嵌套类成员的访问没有任何特权，嵌套类对外围类成员的访问也同样如此，
    它们都遵循普通类所具有的标号访问控制。
    */
    class In {
    public:
        In() {
            cout << "In" << endl;
            cout << test << endl;
        }
        ~In() {
            cout << "~In" << endl;
        }

    private:
        int test;
    };

private:
    In in;
    int i;
};

Out::In in1;

int main()
{
    Out out;

    return 0;
}
