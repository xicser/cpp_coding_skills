/*
����ָ���໥���������bug
*/

#ifndef __MUTUAL_REFERENCE_H__
#define __MUTUAL_REFERENCE_H__

#include <memory>
#include <iostream>

using namespace std;

class Mouse;

class Cat {
public:
    Cat(int age, int height) : height(height) {
        this->age = age;
        cout << "construct Cat" << endl;
    }
    ~Cat() {
        cout << "destruct Cat" << endl;
    }

    void catBarking(void) {
        cout << "Cat_Barking" << endl;
    }

    //��ȡ����
    int getAge(void) {
        return this->age;
    }

    //��ȡ���
    int getHeight(void) {
        return this->height;
    }

//    shared_ptr<Mouse> ppMouse;
    weak_ptr<Mouse> ppMouse;  //����໥��������
private:
    int age;
    int height;
};

class Mouse {
public:
    Mouse(int age, int height) : height(height) {
        this->age = age;
        cout << "construct Mouse" << endl;
    }
    ~Mouse() {
        cout << "destruct Mouse" << endl;
    }

    void mouseBarking(void) {
        cout << "Mouse_Barking" << endl;
    }

    //��ȡ����
    int getAge(void) {
        return this->age;
    }

    //��ȡ���
    int getHeight(void) {
        return this->height;
    }

//    shared_ptr<Cat> ppCat;
    weak_ptr<Cat> ppCat;  //����໥��������
private:
    int age;
    int height;
};

void test_mutual_ref_ptr(void);

#endif // __MUTUAL_REFERENCE_H__
