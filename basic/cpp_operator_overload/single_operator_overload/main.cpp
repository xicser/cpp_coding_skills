#include <iostream>

using namespace std;

/*
�������������
*/
class Counter {

private:
    int v;

public:
    Counter() {
    }
    Counter(int v) {
        this->v = v;
    }

    //ǰ׺����
    Counter operator++() {
        v++;
        return *this;
    }

    //��׺����
    Counter operator++(int) {
        Counter t;
        t.v = v++;
        return t;
    }

    void display() {
        cout << v << endl;
    }
};

/*
�����±������
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
    c = c1++;           //����Ϊ: c = c1.operator++(int);
    c.display();
    c1.display();

    c = ++c2;           //����Ϊ: c = c2.operator++();
    c.display();
    c2.display();
}

void test2()
{
    CharArray str1(7);
    char *str2 = "string";

    for (int i = 0; i < 9; i++) {
        str1[i] = str2[i];     //str1[i] ����Ϊ: operator[](i)
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
    test2();

    return 0;
}
