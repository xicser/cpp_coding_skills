#include <iostream>

using namespace std;

/*
重载自增运算符
*/
class Counter {

private:
    int v;

public:
    Counter() {
        this->v = 0;
    }
    Counter(int v) {
        this->v = v;
    }

    //前缀运算
    Counter operator++() {
        v++;
        return *this;
    }

    //后缀运算
    /**
const的作用:它与内置类型为不致；你法活得你所期望的结果，因为第次返回的是旧值，不是原对象，你调两次后
置++，结果只累加了次，所以我们必须动禁其合法化，就要在前加上const。
内置类型不允许i++++; 这种貌似想要加两次的写法
    */
    const Counter operator++(int) {
        Counter t;
        t.v = v++;
        return t;
    }

    void display() {
        cout << v << endl;
    }
};

/*
重载下标运算符
*/
class CharArray {
private:
    int length;
    char *buff;

public:
    CharArray(int i) {
        length = i;
        buff = new char[length];
    }

    ~CharArray() {
        delete buff;
    }

    int getLength() {
        return length;
    }
    void display() {
        cout << buff << endl;
    }

    char &operator[](int i) {
        if (i < length && i >= 0) {
            return buff[i];
        }
        else {
            cout << endl << "Array index out of range." << endl;
            return buff[length - 1];
        }
    }
};

void test1()
{
    Counter c1(3), c2(3), c;
    c = c1++;           //解释为: c = c1.operator++(int);
    c.display();
    c1.display();

    c = ++c2;           //解释为: c = c2.operator++();
    c.display();
    c2.display();
}

void test2()
{
    CharArray str1(7);
    char *str2 = "string";

    for (int i = 0; i < 9; i++) {
        str1[i] = str2[i];     //str1[i] 解释为: operator[](i)
    }
    cout << endl;

    for (int i = 0; i < 9; i++) {
        cout << str1[i];
    }
    cout << endl;

    cout << str1.getLength() << endl;
}

int main()
{
    // test1();
//    test2();
//    int i = 0;
//    i++++;
//    Counter cnt(3);
//    cnt++++;
//    cnt.display();

    return 0;
}
