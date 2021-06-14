/*
智能指针相互引用引起的bug
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

    //获取年龄
    int getAge(void) {
        return this->age;
    }

    //获取身高
    int getHeight(void) {
        return this->height;
    }

//    shared_ptr<Mouse> ppMouse;
    weak_ptr<Mouse> ppMouse;  //解决相互引用问题
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

    //获取年龄
    int getAge(void) {
        return this->age;
    }

    //获取身高
    int getHeight(void) {
        return this->height;
    }

//    shared_ptr<Cat> ppCat;
    weak_ptr<Cat> ppCat;  //解决相互引用问题
private:
    int age;
    int height;
};

void test_mutual_ref_ptr(void);

#endif // __MUTUAL_REFERENCE_H__
